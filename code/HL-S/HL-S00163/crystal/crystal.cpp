#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],bq[N];

int main(){
	freopen("crystal1.in","r",stdin);
	freopen("crystal1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
	}
	bq[1]=b[1];
	for(int i=2;i<=n-1;i++){
		bq[i]=bq[i-1]+b[i];
	}
	for(int i=n-1;i>=1;i--){
		if(b[i]<=m){
			cout<<b[i];
			return 0;
		}
	}
	cout<<0;
	return 0;
}
/*
-3 -1 2 2 7

*/
