#include<bits/stdc++.h>
using namespace std;
long long a,n;
string s;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(long long j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    long long ans=0,t=s.size();
    for(long long i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[t-i-1])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
