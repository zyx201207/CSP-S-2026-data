#include <bits/stdc++.h>
using namespace std;


long long n,a;
string c,d;
int ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		cin >> d;
		for(int j=1;j<=a;j++){
		c=c+d;
		}
	}
	for(int i=0;i<=c.size()/2;i++){
		if(c[i]!=c[c.size()-i-1]){
			c[c.size()-i-1]=c[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}  
