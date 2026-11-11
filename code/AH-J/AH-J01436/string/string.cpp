#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;vector<ll>a(n),s(n+1);
    vector<char>c(n);
    for(int i=0;i<n;i++){cin>>a[i]>>c[i];s[i+1]=s[i]+a[i];m+=a[i];}
    for(int i=1;i<n;i++){
        if(c[i]==c[i-1])
            a[i]+=a[i-1],c.erase(c.begin()+i-1,c.begin()+i),a.erase(a.begin()+i-1,a.begin()+i),i--;
    }n=a.size();
    if(n<2)return cout<<0,0;
    if(n==2&&a[0]==a[1])return cout<<m/2,0;
    for(int i=0;i<m/2;i++){
        auto f1=upper_bound(s.begin(),s.end(),i);
        auto f2=upper_bound(s.begin(),s.end(),m-i-1);
        int x1=f1-s.begin(),x2=f2-s.begin();
        if(c[x1]!=c[x2])b++;
    }cout<<b;
    return 0;
}
