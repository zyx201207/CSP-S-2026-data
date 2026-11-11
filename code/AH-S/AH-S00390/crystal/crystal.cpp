#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],cnt,s[2000005],x[200005];
bool flag;
void update(int root,int l,int r,int x,int y,int k){
    if(l==r){
        s[root]+=k;
        return ;
    }
    int mid=(l+r)/2;
    if(x<=mid) update(root*2,l,mid,x,y,k);
    if(y>mid) update(root*2+1,mid+1,r,x,y,k);
    s[root]=s[root*2]+s[root*2]+1;
}
int query(int root,int l,int r,int x,int y){
    if(l==r) return s[root];
    int mid=(l+r)/2,ans=0;
    if(x<=mid) ans+=query(root*2,l,mid,x,y);
    if(y>mid) ans+=query(root*2+1,mid+1,r,x,y);
    return ans;
}
signed main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i],x[i]=a[i];
sort(a+1,a+n+1);
for(int i=1;i<=n;i++){
    b[i]=a[i]-a[i-1];
    if(i>2&&b[i]!=b[i-1]) flag=1;
}
b[n+1]=1;
if(flag==0){
    int num=0,c=b[n];
    while(m>0){
        num++;
        m-=num*c;
    }
    cnt=num;
    if(m==0) cnt++;
}else{
    for(int k=0;k<n-1;k++){
        int i=k,w=m,ans=1;
        memset(s,0,sizeof(s));
        while(w>0&&i<n-1){
            i++;
            w-=i*b[i+1];
            update(1,1,n,1,i,b[i+1]);
        }
        for(int i=1;i<=n;i++){
            a[i]+=query(1,1,n,i,i);
            if(a[i]==a[i-1]) ans++;
            a[i-1]=x[i-1];
        }
        cnt=max(cnt,ans);
    }
}
cout<<cnt;
return 0;
}
