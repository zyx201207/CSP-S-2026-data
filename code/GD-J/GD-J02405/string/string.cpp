#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int N=2e5+5;
int a[N];
ll ans;
char c[N];
string s;

stack<char> v;

bool hui(string s){
	string x="";
	for(ll i=s.size()-1; i>=0; i--){
		x=x+s[i];
	}
	if(x==s){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin >> n;
	for(ll i=1; i<=n; i++){
		cin >> a[i] >> c[i];
		for(int j=1; j<=a[i]; j++){
			s=s+c[i];
		}
	}
	ll len=s.size()-1;
	if(hui(s)==1){
		cout << 0 <<endl;
		return 0;
	}
	for(ll i=len; i>=0; i--){
		v.push(s[i]);
	}
	
	
	while(len<v.size()){
		if(v.top()!=s[len]){
			ans++;
		}
		v.pop();
		len--;
	}
	cout << ans/2 << endl;
	
	
		
	return 0;
} 


