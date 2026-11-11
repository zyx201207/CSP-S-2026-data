#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long bzd=n;
	for(int i=n;i>=1;i--){
		num=0;
		for(int j=i;j>=1;j--){
			num+=abs(a[i]-a[j]);
			if(num>m) break;
		}
		if(num<=m){
			cout<<bzd;
			return 0;
		}else{
			bzd--;
		}
	}
	return 0;
}
