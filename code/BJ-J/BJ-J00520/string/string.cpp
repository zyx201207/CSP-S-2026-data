#include<bits/stdc++.h>
using namespace std;
vector<long long>a(200003);
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    string s="";
    int n,i1,j1,tot=0,ans=0;
    cin>>n;
    a.resize(n+1);
    char c[n+3];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        tot+=a[i];
        for(int j=1;j<=a[i];j++)s+=c[i];
    }
    string s1=s.substr(0,tot/2);
    string s2=s.substr((tot%2==0?tot/2:tot/2+1),tot);
    reverse(s2.begin(),s2.end());
    for(int i=0,i<n;i++){
        if(s1[i]!=s2[i])ans++;
    }
    cout<<ans;
    return 0;
}
