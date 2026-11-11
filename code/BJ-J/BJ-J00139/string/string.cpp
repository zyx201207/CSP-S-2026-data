#include <bits/stdc++.h>
using namespace std;
string s;
long long n,sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        char c;
        cin>>x>>c;
        for(long long j=1;j<=x;j++){
            s+=c;
        }
    }
    for(long long i=0;i<(long long)(s.size()/2);i++){
        if(s[i]!=s[(long long)s.size()-i-1]) sum++;
    }
    cout<<sum<<endl;
    return 0;
}