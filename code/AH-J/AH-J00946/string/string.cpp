#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
char c[100005],s1[10000005],s2[100000005];
ll a[100005],ans=0,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	ll len=s.size();
	for(ll i=(len-1)/2-1;i>=0;i--){
		s1[i]=s[i];
	}
	for(ll i=len-1;i>=(len-1)/2+1;i--){
		s2[i]=s[i];
	}
	for(ll i=(len-1)/2+1;i<=len-1;i++){
		for(ll j=(len-1)/2-1;j>=0;j--){
			if(s1[j]!=s[i]){
				cnt++;
				break;
			}
		}
	}
	for(ll i=0;i<=(len-1)/2-1;i++){
		for(ll j=len-1;j>=(len-1)/2+1;j--){
			if(s2[j]!=s[i]){
				ans++;
				break;
			}
		}
	}
	ll maxn=-1e9;
	maxn=max(cnt,ans);
	cout<<maxn;
	return 0;
}
