#include <bits/stdc++.h>
#define ll int
using namespace std;
ll n,m;
string s;
ll a[500005];
ll b[500005];
bool qwe[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool asd = 1;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
		if(a[i] < a[i-1]) asd = 0;
	}
	if(m == 2){
		b[a[n]] = n;
		for(int i = 1;i <= n;i ++){
			if(a[i] != a[n]){
				b[a[i]] ++;
			}
		}
		for(int i = 1;i <= m;i ++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	if(asd){
		ll l = 1;
		for(int i = 1;i <= n;i ++){
			b[a[i]] = b[a[i-1]]+1;
		}
		for(int i = 1;i <= m;i ++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	for(int i = 1;i <= n;i ++){
		s = "";
		for(int j = i;j <= n;j ++){
			if(s.find(a[j]+'0') == -1){
				s += a[j]+'0';
			} else {
				s.erase(s.find(a[j]+'0'));
				s += a[j]+'0';
			}
		}
		for(int j = 1;j <= m;j ++){
			if(s.find(j+'0') != -1){
				b[j] ++;
			}
		}
	}
	for(int i = 1;i <= m;i ++){
		cout<<b[i]<<" ";
	}
	return 0;
}
