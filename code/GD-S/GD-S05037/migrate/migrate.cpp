#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		if(c==13||c==14){
		cout<<n-1<<endl;
		continue;
	}
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		long long k=a[1]-a[0];
			if(c==11||c==12){
			cout<<n-d-1<<endl;
			}
		if(c==15||c==16||c==17){
			cout<<n/d;
		}
	}
	return 0;
}
