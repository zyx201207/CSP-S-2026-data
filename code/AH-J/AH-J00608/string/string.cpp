#include <bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
struct node{
    int s,e;char c;
}t[N];
int n,a[N],s[N],cnt;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')if(c=='-')f=-1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        cin>>a[i]>>t[i].c;
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        t[i].s=s[i]-a[i]+1,t[i].e=s[i];
    }
//    cout<<t[n].e<<'\n';
    for(int l=1,r=t[n].e,i=1,j=n;l<=t[n].e/2;l++,r--){
        if(l>t[i].e)++i;
        if(r<t[j].s)--j;
//        cout<<t[i].c<<' '<<t[j].c<<'\n';
        if(t[i].c!=t[j].c)cnt++;
    }
    cout<<cnt;
    return 0;
}
