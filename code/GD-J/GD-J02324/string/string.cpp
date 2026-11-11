#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string","w",stdin);
	freopen("string","r",stdout);
	int n,m;
	long long a[1000000010];
	string c[];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]<<c[i];
		for(int i=1;i<=n;i++){
		if(c[i]==c[i+n]){
			cout<<"0";
			return 0;
		}
		if(c[i]!=c[i+n]){
			m=(c[i+n]-c[i])*a[i];
			cout<<m;
		}
	}
	return 0;
}
