#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n;
ll a[N];
char s[N];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;return 0;
    }
    ll bj1=0,bj2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        if(a[i]==a[i-1]&&bj1!=-1||i==1){
             bj1=a[i];
        }
        else bj1=-1;
        if(s[i]!=s[i-1]&&i!=1) bj2=1;
    }

    if(bj2==0) {
        cout<<0;
        return 0;
    }//cout<<bj1;
    if(bj1!=-1){
        ll cnt=0;
        for(int i=1;i*2<=n;i++){

            if(s[i]!=s[n+1-i]) cnt++;
        }

        cout<<cnt*bj1;
        return 0;
    }
    string p="";
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i];j++){
            p+=s[i];
        }
    }
    ll cnt=0;
    n=p.size();
    for(int i=0;i*2<n;i++){
        if(p[i]!=p[n-1-i]) cnt++;
    }
    cout<<cnt;
    return 0;

}
