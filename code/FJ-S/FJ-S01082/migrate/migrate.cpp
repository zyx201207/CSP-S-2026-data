#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		if(n%2==0){
			cout<<(n+1)/d/2;
		}else{
			cout<<(n+1)-(2*d);
		}
	}
	return 0;
}

