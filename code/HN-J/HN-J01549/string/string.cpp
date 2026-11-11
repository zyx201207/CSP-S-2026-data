#include <bits/stdc++.h>
using namespace std;
	long long n;
	pair<long long ,char> a[200005];
	string s;
	vector<char> c;
	long long len,ans,p;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	cin >> n ;
	for(int i=1; i<=n; i++){
		int q;
		char cc;
		cin >> q >> cc ;
		for(int j=len,k=1; k<=q; j++,k++){
			c.push_back(cc);
		}
		len+=q-1;
		p+=q;
}
	for(int i=0; i<p/2; i++){
		if(c[i] != c[p-i-1]){
			ans++;
		} 
	}
	cout << ans ;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
