#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,ans,a;
char s[2000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=1;i<=n;i++){
        char b;3
        cin>>a>>b;
        cnt+=a;
        for(long long j=cnt-a;j<=cnt;j++)  s[j]=b;
    }
    for(long long i=1;i<=(cnt>>1);i++)
        if(s[i-1]!=s[cnt-i]) ans++;
    cout<<ans;
return 0;
}
