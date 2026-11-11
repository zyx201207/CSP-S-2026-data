#include<bits/stdc++.h>
using namespace std;
int c,t,a[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x=a[2]-a[1];
		int m=k/x;
		cout<<n+1-2*m<<endl;
	}
	return 0;
}
