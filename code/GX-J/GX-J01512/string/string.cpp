#include<bits/stdc++.h>
using namespace std;
const int N=100000050;
long long n;
long long b[N],ans=0,cnt=0;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    string s;
    for(long long i=1;i<=n;i++){
        cin>>b[i]>>c[i];
        cnt+=b[i];
        for(long long j=0;j<=b[i];j++){
            s+=c[i];
        }
    }
    for(long long i=1;i<=cnt/2;i++)
            if(s[i]!=s[cnt-i+1]) ans++;
    cout<<ans;
    return 0;
}
