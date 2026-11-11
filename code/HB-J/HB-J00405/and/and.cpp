#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,shu;
vector<ll> v;
string ji,ans,d;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
     while(v[n-1]){
            ji+=to_string(v[n-1]%2);
            v[n-1]/=2;
    }
    ans=ji;
    ji="";
    for(int i=0;i<m-1;i++){
        while(v[n-2-i]){
            ji+=to_string(v[n-2-i]%2);
            v[n-2-i]/=2;
        }
        for(int j=0;j<ji.size();j++){
            if(ji[j]==ans[j]) d+='1';
            else d+='0';
        }
        ans=d;
        ji="";
        d="";
    }
    for(int i=0;i<ans.size();i++) if(ans[i]=='1')shu+=pow(2,i);
    cout<<shu;
    return 0;
}
