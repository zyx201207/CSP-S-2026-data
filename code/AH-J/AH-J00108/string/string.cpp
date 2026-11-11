#include <bits/stdc++.h>
using namespace std;
string z="";
long long int n,ai,ans=0;
char ci;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>ai>>ci;
		for(int j=1; j<=ai; j++) z+=ci;
	}
	int l=0,r=z.size()-1;
	while(l<r) ans+=(z[l]==z[r] ? 0 : 1),l++,r--;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
