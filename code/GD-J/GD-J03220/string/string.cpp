#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int> a;
vector<char> c;
ll cnt,ans;
string m;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		a.push_back(x);
		c.push_back(y);
		cnt+=x;
		for(int i=1;i<=x;i++)
			m+=y;
			
	}	
	for(ll i=0;i<cnt/2;i++){
		if(m[i]!=m[cnt-i-1])
			ans++; 
	}
	cout<<ans;
	return 0;
} 
