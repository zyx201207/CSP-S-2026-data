#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans=0,cnt1=0;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int cnt=a[2]-a[1];
    for(int i=1;i<=n;i++){
        if(m<=cnt1)break;
        cnt1+=cnt*i;ans++;
    }
    cout << ans;
    return 0;
}