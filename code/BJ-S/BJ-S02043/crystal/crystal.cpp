#include<bits/stdc++.h>
using namespace std;
long long n,m,s[500009],dq,ans;
struct zyd{
    long long l,r,sum,jia;
}tr[2000009];
void build(long long z,long long y,long long root){
    tr[root].l=z;
    tr[root].r=y;
    tr[root].jia=0;
    tr[root].sum=0;
    if(z==y){
        return;
    }
    long long mid=(z+y)/2;
    build(z,mid,root*2);
    build(mid+1,y,root*2+1);
    return;
}
void ly(long long root){
    if(tr[root].jia!=0){
        tr[root*2].jia+=tr[root].jia;
        tr[root*2+1].jia+=tr[root].jia;
        tr[root*2].sum+=tr[root].jia*(tr[root*2].r-tr[root*2].l+1);
        tr[root*2+1].sum+=tr[root].jia*(tr[root*2+1].r-tr[root*2+1].l+1);
        tr[root].jia=0;
    }
    return;
}
void add(long long z,long long y,long long root,long long zuo,long long you,long long k){
    if(z>you||y<zuo||zuo>you){  
        return;
    }
    if(zuo<=z&&y<=you){
        tr[root].jia+=k;
        tr[root].sum+=k*(tr[root].r-tr[root].l+1);
        return;
    }
    ly(root);
    long long mid=(z+y)/2;
    add(z,mid,root*2,zuo,you,k);
    add(mid+1,y,root*2+1,zuo,you,k);
    tr[root].sum=tr[root*2].sum+tr[root*2+1].sum;
    return;
}
long long cha(long long z,long long y,long long root,long long zuo,long long you){
    if(z>you||y<zuo||zuo>you){  
        return 0;
    }
    if(zuo<=z&&y<=you){
        return tr[root].sum;
    }
    ly(root);
    long long mid=(z+y)/2;
    return cha(z,mid,root*2,zuo,you)+cha(mid+1,y,root*2+1,zuo,you);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int a=1;a<=n;a++){
        cin>>s[a];
    }
    build(1,n,1);
    sort(s+1,s+n+1);
    for(long long z=1,y=1;y<=n;y++){
        add(1,n,1,z,y-1,s[y]-dq);
        m-=(y-z)*(s[y]-dq);
        dq=s[y];
        while(m<0&&z<y){
            long long fd=cha(1,n,1,z,z);
            m+=fd;
            add(1,n,1,z,z,-1*fd);
            z++;
        }
        ans=max(ans,y-z+1);
    }
    cout<<ans;
    return 0;
}