#include <bits/stdc++.h>
#define int long long
#define vector basic_string
#define pii array<int,2>
using namespace std;
int read(){
    int s=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        s=s*10+(ch-'0');
        ch=getchar();
    }
    return s*f;
}
int n,m,a[500010],s[500010],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1,j=0;i<=n;i++){
        while(a[i]*(i-j)-(s[i]-s[j])>m) j++;
        ans=max(ans,i-j);
    }
    printf("%lld\n",ans);
    return 0;
}