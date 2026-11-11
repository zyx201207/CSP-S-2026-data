#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m=0,j,ans,s,z,zz,p;
vector<ll> c,b,an,a;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>j;
        a.push_back(j);
        p+=j;
    }
    p/=n;
    a.push_back(p);
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        if(a[i]==p){
            if(abs(a[i-1]-p)<abs(a[i+1]-p)) z=a[i-1];
            else z=a[i+1];
            continue;
        }
    }

    for(int i=0;i<a.size();i++) c.push_back(abs(z-a[i]));
    sort(c.begin(),c.end());
    for(int i=0;i<c.size();i++){
        if(m>=c[i]){
            ans++;
            m-=c[i];
            if(m==0) continue;
        }
        else continue;
    }
    cout<<ans-1;
    return 0;
}
