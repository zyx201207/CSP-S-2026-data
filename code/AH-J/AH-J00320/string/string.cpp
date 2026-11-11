#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,x,k=0;
    char a;
    string s;
    cin>>n;
    while(n--){
        cin>>x>>a;
        while(x--) s+=a;
    }
    ll l=s.size(),r=s.size();
    l/=2;
    for(ll i=0,j=r-1;i<l;i++){
        if(s[i]!=s[j]) k++;
        j--;
    }
    cout<<k;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
