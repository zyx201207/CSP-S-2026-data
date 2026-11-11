#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],mx;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int he=0;
	for(int i=1,j=1;j<=n;){
		if(he<=m){
			j++;
			he+=(j-i)*(a[j]-a[j-1]);
		}
		else {
			i++;
			he-=(a[j]-a[i]);
		}
		mx=max(mx,j-i);
	}
	cout<<mx;
	return 0;
}
