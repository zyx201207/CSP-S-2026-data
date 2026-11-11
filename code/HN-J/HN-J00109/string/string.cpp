#include<bits/stdc++.h>
#define LL long long
#define Uint unsigned int
#define ULL unsigned LL
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define fr first
#define se second
#define pb push_back
#define isr insert
#define _i128 __int128
using namespace std;
const int N = 2e5+5;
LL n,a[N],ans;
char c[N];
LL read(){
    LL su=0,pp=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')pp=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){su=su*10+ch-'0';ch=getchar();}
    return su*pp;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
        {a[i]=read();cin>>c[i];}
    for(int i=1,j=n;i<j;){
        if(c[i]!=c[j])ans+=min(a[i],a[j]);
        if(a[i]<a[j])a[j]-=a[i],i++;
        else if(a[i]>a[j])a[i]-=a[j],j--;
        else i++,j--;
    }
    cout<<ans<<"\n";
    return 0;
}
