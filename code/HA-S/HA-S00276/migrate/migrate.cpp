#include<bits/stdc++.h>
using namespace std;
int a[int(2e6)+10];
int sum[int(2e6)+10];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n,d;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			sum[i]=a[i]-a[i-1];
		}
		if(sum[0]>=d){
			cout<<0<<endl;
		}
	}
	return 0;
}
