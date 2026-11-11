#include<bits/stdc++.h>
using namespace std;
long long a[200010],n;
long long l,ans=0;
char c[200020];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        cin>>c[i];
        for(long long j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    l=s.size();
    for(long long i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
