#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s=s+a[i];
		}
		cout<<s/n-1;
	}
	return 0;
}
