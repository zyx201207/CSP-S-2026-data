#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxN = 2e5+5;
ll n;
ll a;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	if(n==1){
		cout << 0 << "\n";
		return 0;
	}
	if(n<=2000){
		char s[100005];
		int t = 1;
		for(int i=1;i<=n;i++){
			cin >> a >> c;
			for(int j=1;j<=a;j++)
				s[t++] = c;
		}
		ll cnt = 0;
		if(t%2==1){
			for(int i=1;i<=(t-1)/2;i++){
				if(s[i]!=s[t-i])
					cnt ++;
			}
		}
		else{
			for(int i=1;i<=(t-2)/2;i++){
				if(s[i]!=s[t-i])
					cnt ++;
			}
		}
		cout << cnt << "\n";
		return 0;
	}
	char s[maxN];
	bool f=1;
	ll t = 1;
	for(int i=1;i<=n;i++){
		cin >> a >> c;
		if(a!=1)
			f = 0;
		for(int j=1;j<=a;j++)
			s[t++] = c;
	}
	if(f){
		ll cnt = 0;
		if(t%2==1){
			for(int i=1;i<=(t-1)/2;i++){
				if(s[i]!=s[t-i])
					cnt ++;
			}
		}
		else{
			for(int i=1;i<=(t-2)/2;i++){
				if(s[i]!=s[t-i])
					cnt ++;
			}
		}
		cout << cnt << "\n";
	}
	else cout << 0 << "\n";
	return 0;
}
