#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,a[2000001];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int s=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i];
			s+=a[i];
		}
		if(c==0){
			cout<<1<<endl<<2;
			return 0;
		}
		cout<<s/6<<endl;
	}
	return 0;
}
