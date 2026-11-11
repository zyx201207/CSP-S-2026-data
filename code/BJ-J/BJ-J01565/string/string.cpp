#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum=0,ans=0;
string s;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(long long j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
