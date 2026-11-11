#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int M=2e5+5;
char c[M];
int n,i=0,ans=0;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        int ai;
        char ci;
        cin>>ai>>ci;
        for(int j=i;j<i+ai;j++) c[j]=ci;
        i+=ai;
    }
    for(int j=0;j<i/2;j++){
        if(c[j]!=c[i-1-j]) ans++;
    }
    cout<<ans;
    return 0;
}
