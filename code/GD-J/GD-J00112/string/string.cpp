#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n,ans;
ll sum;
char b;

vector<char> a;

void solve(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> sum >> b;
		while(sum--)a.push_back(b);
	}
	ll j=a.size();
	if(j%2==0){
		for(int i=1;i<=j/2+1;i++){
			if(a[i-1]!=a[j-i]){
				ans++;
			}
		}
	}
	else{
		for(int i=1;i<=j/2;i++){
			if(a[i-1]!=a[j-i]){
				ans++;
			}
		}
	}
	cout << ans<<endl;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
