#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[100010];
ll n;
string c;
bool d=1;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n; 
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
	}
	for(int i=1; i<=n; i++){
		if(c[1]!=c[i]){
			d=0;
		}
	}
	if(d==1){
		cout<<0;
	}
	
	return 0;
}
