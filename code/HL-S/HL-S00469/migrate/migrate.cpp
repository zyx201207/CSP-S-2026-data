#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	long long n,d;
	long long cnt=0;
	while(t--){
		cin>>n>>d;
		long long a[n+1];
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		cnt=0;
		for(long long i=1;i<n-2;i++){
			if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d){
				if(a[i+3]-a[i]>d&&a[i+3]-a[i]<2*d){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}