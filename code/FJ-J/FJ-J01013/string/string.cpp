#include <bits/stdc++.h>
using namespace std;
string a;
long long ans,n,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	while(n--){
		long long x; char y;
		cin>>x>>y;
		sum+=x;
		while(x--) a+=y;
	}
	for(int i=0;i<sum/2;i++){
		if(a[i]!=a[sum-i-1]) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
