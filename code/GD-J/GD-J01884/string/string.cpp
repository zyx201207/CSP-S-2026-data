#include<bits/stdc++.h>
using namespace std;
typedef string str;
typedef long long ll;
const ll N=2*1e5+10;
string s;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		ll x;
		string y;
		cin>>x>>y;
		for(int i=sum;i<sum+x;i++){
			s+=y;
		}
		sum+=x;
	}
	ll l=0,r=sum,ans=0;
	while(l<=r){
		if(s[l]!=s[r])ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
} 
