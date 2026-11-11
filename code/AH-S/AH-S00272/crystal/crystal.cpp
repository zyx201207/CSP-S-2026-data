#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005],s=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){cout<<"1";return 0;}
	sort(a+1,a+n+1);
	int tm=0,ts=0;
	for(int j=2;j<=n;j++){
		tm=0;ts=1;
		for(int jj=j-1;jj>=1;jj--){
			tm+=a[j]-a[jj];
			if(tm<=m) ts++;
			else break;
		}
		if(ts>s) s=ts;
	}
	cout<<s;
	return 0;
}
