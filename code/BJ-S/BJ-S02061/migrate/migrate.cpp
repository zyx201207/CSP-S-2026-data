#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+10;
int C,T,n,d,a[N];
int f[N],dep[N],lst[N];
struct node{
    int l,r;
}b[N];
unordered_map<int,int> mp;
void solve1_10ormore(){
    for(int i=2,l=1;i<=n;i++){
        while(a[i]-a[l]>d) l++;
        lst[i]=l;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        mp[0]=i,f[i]=1;
        for(int j=i+1;j<=n;j++){
            int l=max(i,lst[j]);
            if(l==j) break;
            int r=mp[dep[l]];
            f[j]=f[r]-f[l-1];
            ans+=(f[j]==2);
            f[j]+=f[j-1],mp[dep[j]=dep[l]+1]=j;
        }
        for(int j=i;j<=n;j++){
            int l=max(i,lst[j]);
            if(j!=i && l==j) break;
            dep[j]=f[j]=0;
        }
        mp.clear();
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) lst[i]=0;
    return;
}
void solve11_12(){
    int dc=a[2]-a[1];
    int tiao=d/(dc);
    if(tiao<=1) puts("0");
    else{
        if(n<2*tiao) puts("0");
        else printf("%lld\n",n-2*tiao+1);
    }
}
void solve13_14(){
    for(int i=2,l=1;i<=n;i++){
        while(a[i]-a[l]>d) l++;
        lst[i]=l;
    }
    int ans=0;
    for(int i=1;i<=10;i++){
        mp[0]=i,f[i]=1;
        for(int j=i+1;j<=n;j++){
            int l=max(i,lst[j]);
            if(l==j) break;
            int r=mp[dep[l]];
            f[j]=f[r]-f[l-1];
            ans+=(f[j]==2);
            f[j]+=f[j-1],mp[dep[j]=dep[l]+1]=j;
        }
        for(int j=i;j<=n;j++){
            int l=max(i,lst[j]);
            if(j!=i && l==j) break;
            dep[j]=f[j]=0;
        }
        mp.clear();
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) lst[i]=0;
    return;
}
void fenlei(){
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(n==1){
        puts("0");
        return;
    }
    if(C<=10) solve1_10ormore();
    else if(11<=C && C<=12) solve11_12();
    else if(13<=C && C<=14) solve13_14();
    else solve1_10ormore();
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&C,&T);
    while(T--) fenlei();
    return 0;
}
