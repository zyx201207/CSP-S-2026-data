#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[200001];
char ch[200001];
ll n;
void solve1(){
    string s="";
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=x[i];j++){
            s+=ch[i];
        }
    }
    ll ans=0;
    for(ll i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            ans++;
        }
    }
    cout<<ans;
}
void solve2(){
    ll ans=0;
    ll l=1,r=n;
    while(l<r){
        if(ch[l]!=ch[r]){
            if(x[l]>x[r]){
                ans+=x[r];
                r--;
                if(ch[l]!=ch[r]){
                    ans+=x[l]-x[r+1];
                    l++;
                }
            }
            else{
                ans+=x[l];
                l++;
                if(ch[l]!=ch[r]){
                    ans+=x[r]-x[l];
                    r--;
                }
            }
        }
        else{
			l++;
			r--;
		}
    }
    cout<<ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ll sum=0;
    for(ll i=1;i<=n;i++){
        cin>>x[i]>>ch[i];
        sum+=x[i];
	}
    if(sum<=500){
        solve1();
    }
    else{
        solve2();
    }
    return 0;
}
