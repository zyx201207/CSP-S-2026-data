#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ans=0;
	string s;
	cin >> n;
	while(n--){
		cin >> a;
		cin >> s;
		int b=a;
		ans+=b;
	}
	cout  << ans/2; 
	return 0;
}

