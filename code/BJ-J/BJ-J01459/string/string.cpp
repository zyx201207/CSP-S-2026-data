#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        long long x;
        char y;
        cin>>x>>y;
        for(int j=1;j<=x;j++)s=s+y;
    }
    long long j=s.size();
    long long k=(j-1)/2+1,ans=0;
    for(int i=0;i<k;i++){
        j--;
        if(s[i]==s[j])ans++;
    }
    cout<<k-ans;
    return 0;
}
