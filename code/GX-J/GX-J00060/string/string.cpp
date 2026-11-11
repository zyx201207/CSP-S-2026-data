#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        string c;
        cin>>x>>c;
        for(long long j=1;j<=x;j++){
            s+=c;
        }
    }
    cout<<s<<endl;
    long long l=0,r=s.size()-1;
    while(l<=r){
        cout<<s[l]<<" "<<s[r]<<endl;
        if(s[l]!=s[r])ans++;
        l++,r--;
    }
    cout<<ans;
}

