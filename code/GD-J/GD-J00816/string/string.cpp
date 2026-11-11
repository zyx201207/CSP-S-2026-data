#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,ans;
	string a,c;
	cin>>n;
	while(n--){
		cin>>m>>c;
		while(m--) a.append(c);
	}
	int l=0,r=a.length()-1;
	while(l<r){
		if(a[l]!=a[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
