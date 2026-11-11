#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,sum;
long long a[2000020];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t>0){
		t--;
		sum=0;
		cin>>n>>d;
		if(n<=3){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-2;i++){
			if(a[i+2]<=a[i]+d&&a[i+3]>a[i]+d&&a[i+3]<=a[i+2]+d) sum++;
		}
		cout<<sum;
	}
}
