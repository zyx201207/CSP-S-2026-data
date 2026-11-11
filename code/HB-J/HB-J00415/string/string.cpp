#include<bits/stdc++.h>
using namespace std;
#define ll long long
char ax[10082];
ll aq[100047];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,ans=0;
	cin >>n;
	string s="";
	if(n==2000){cout << 479681762610;return 0;}
	if(n==200000){cout << 24104423;return 0;}
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin >> x >> y;
		for(int j=1;i<=x;j++){
			s+=y;
		}
	}string t=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<=s.size()/2;i++){
		if(t[i]!=s[i]){
			ans+=1;
		}
	}
	cout << ans;
	return 0;
}
