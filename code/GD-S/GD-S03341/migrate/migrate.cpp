#include<bits/stdc++.h>
using namespace std;
int a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	int n,m;
	int n1;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		n1=n;
		while(a[n1]=a[n1-1]&&n1-1!=0){
			n1--;
		}
		if(n1=1) cout<<n-m-m+1;
	}
	return 0;
}
