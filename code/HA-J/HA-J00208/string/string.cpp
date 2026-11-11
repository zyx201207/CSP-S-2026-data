#include<bits/stdc++.h>
using namespace std;
long long n,x,ans,i,e;
string p;
vector<string> a;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--) {
		cin>>x>>p;
		while(x--) {
			a.push_back(p);
		}
	}
	e=a.size()-1;
	while(i<e/2) {
		if(a[i]!=a[e-i]) {
			ans++;
		}
		i++;
	}
	cout<<ans<<endl;
	return 0;
}
