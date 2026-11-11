#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],ans;char c[200001];string s="";
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(long long j=0;j<a[i];j++)s+=c[i];
    }
    string s2(s.rbegin(),s.rend());
    for(int i=0;i<s.size()/2;i++) if(s[i]!=s2[i])ans++;
    cout<<ans;
    return 0;
}
