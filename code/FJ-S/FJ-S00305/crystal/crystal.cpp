#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
#define gc getchar
using namespace std;

const int N=5e5+10;
int n,ans;
LL m,a[N];
map<LL,int>p;

LL rd(){
    int f=1;
    LL x=0;char ch=gc();
    while(!isdigit(ch))f=(ch=='-'?-f:f),ch=gc();
    while(isdigit(ch))x=x*10+ch-'0',ch=gc();
    return x*f;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)a[i]=rd(),p[a[i]]++;
    sort(a+1,a+n+1);n=unique(a+1,a+n+1)-a-1;
    LL s=0;
    for(int i=1,j=1,c=0;i<=n;i++){
        s+=1ll*c*(a[i]-a[i-1]);
        while(s>m){
            int x=p[a[j]];
            c-=x;
            s-=1ll*x*(a[i]-a[j]);
            j++;
        }
        c+=p[a[i]];
        ans=max(ans,c+(int)(j==1?0:(m-s)/(a[i]-a[j-1])));
    }
    printf("%d\n",ans);
    return 0;
}