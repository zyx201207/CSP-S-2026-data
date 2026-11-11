#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int a[N],pre[N];
int read(){int x=0,b=1;char c;for(;!isdigit(c);c=getchar()){if(c=='-'){b=-1;}}for(;isdigit(c);c=getchar()){x=x*10+c-'0';}return x*b;}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    int l=1,sum=0,ans=0;
    for(int r=1;r<=n;r++){
        pre[r]=pre[r-1]+a[r];
        while(l<r&&sum>m){
            sum-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
        if(a[r+1]!=a[r]){
            sum+=(a[r+1]-a[r])*(r-l+1);
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
