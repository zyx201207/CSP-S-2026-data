#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
string a1,b1,b2;
ll tuling,baoyou = 0; 
void solve(){
	cin >> tuling;ll o = 0;
	for(ll i = 1;i <= tuling;i++){
		ll m;char y;
		cin >> m >> y;
		for(ll j = o;j < o+m;j++){
			a1[j] = y;
		}o+=m;
	}ll o1 = o/2;
	for(ll i = 0;i < o1;i++){
		b1[i] = a1[i];
	}ll j = 0;
	for(ll i = o-1;i >= o-o1;i--){
		b2[j] = a1[i];
		j++;
	}
	for(ll i = 0;i < o1;i++){
		if(b1[i]!=b2[i]){
			baoyou++;
		}
	}cout << baoyou;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
