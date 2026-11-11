#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s*w;
}
const int N=5e5+5;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=read(),m=read(),l=1,sum=0,ans=0;
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){sum+=a[i];
        while(a[i]*(i-l+1)-sum>m)sum-=a[l],l++;
        ans=max(ans,i-l+1);
    }cout<<ans;
    return 0;
}

//g++ -std=c++14 -O2 A.cpp -o A