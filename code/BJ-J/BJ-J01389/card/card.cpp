#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500009],b[500009],c[500009];
int n,m;
void n5m2(){
    for(int i=1;i<=n;++i){
        int cnt=1;
        for(int j=i;j<=n;++j){
            int f=-1;
            for(int k=1;k<cnt;++k){
                if(c[k]==a[j]){
                    f=k;
                    break;
                }
            }
            if(f==-1){
                c[cnt++]=a[j];
            }else{
                cnt=f;
                c[cnt++]=a[j];
            }
        }
        for(int j=1;j<cnt;++j){
            b[c[j]]++;
        }
    }
    for(int i=1;i<=m;++i){
        cout<<b[i]<<" ";
    }
    cout<<'\n';
}
bool isdd(){
    for(int i=1;i<n;++i){
        if(a[i]>a[i+1])return 0;
    }
    return 1;
}
void dd(){
    for(int i=1;i<=n;++i){
        b[a[i]]=i;
    }
    for(int i=1;i<=m;++i){
        cout<<b[i]<<" ";
    }
    cout<<'\n';
}
int d[500009],g[500009];
void n24e8(){
    for(int i=1;i<=m;++i){
        for(int j=n;j>=1;--j){
            if(a[j]==i){
                d[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=n;++i){
        int cnt=1;
        for(int j=i;j<=n;){
            g[cnt++]=a[j];
            j=d[a[j]]+1;
        }
        for(int j=1;j<cnt;++j){
            b[g[j]]++;
        }
    }
    for(int i=1;i<=m;++i){
        cout<<b[i]<<" ";
    }
    cout<<'\n';
}
void m2(){
    b[a[n]]=n;
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(a[i]!=a[n]){
            cnt++;
        }
    }
    for(int i=1;i<=2;++i){
        if(b[i]==n)cout<<n<<' ';
        else cout<<cnt<<' ';
    }
    cout<<'\n';
}
struct node{
    int l,r,maxx;
}tree[2200009];
void build(int l,int r,int p){
    if(l==r){
        tree[p]={l,r,0};
        return ;
    }
    build(l,(l+r)/2,p*2);
    build((l+r)/2+1,r,p*2+1);
    tree[p]={l,r,max(tree[p*2].maxx,tree[p*2+1].maxx)};
}
void rush(int p,int x,int c){
    if(tree[p].l==tree[p].r){
        tree[p].maxx=c;
        return ;
    }
    if(tree[p*2].r>=x){
        rush(p*2,x,c);
    }else{
        rush(p*2+1,x,c);
    }
    tree[p].maxx=max(tree[p*2].maxx,tree[p*2+1].maxx);
}
int qu(int p,int l,int r){
    if(tree[p].r<l||tree[p].l>r){
        return 0;
    }
    if(l<=tree[p].l&&tree[p].r<=r){
        return tree[p].maxx;
    }
    int aa=qu(p*2,l,r);
    int bb=qu(p*2+1,l,r);
    if(aa<bb){
        return bb;
    }else{
        return aa;
    }
}
int lst[500009],clst[500009];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(n<=500&&m<=200){
        n5m2();
        return 0;
    }
    if(isdd()){
        dd();
        return 0;
    }
    if(n*n<=400000000){
        n24e8();
        return 0;
    }
    if(m==2){
        m2();
        return 0;
    }
    if(m==1){
        cout<<n<<'\n';
        return 0;
    }
    build(1,n,1);
    for(int i=n;i>=1;--i){
        if(lst[a[i]]==0){
            lst[a[i]]=i;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;++i){
        clst[i]=qu(1,i+1,n);
        if(lst[a[i]]!=i){
            rush(1,lst[a[i]],i);
        }
    }
    for(int i=1;i<=n;++i){
        if(clst[lst[a[i]]]>=i||lst[a[i]]==i){
            b[a[i]]+=i-clst[i];
        }
    }
    for(int i=1;i<=m;++i){
        cout<<b[i]<<' ';
    }
    cout<<'\n';
    return 0;
}