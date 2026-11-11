#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		long long a[50005]={};
		long long b[50005]={};
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		long long cnt=1;
		for(long long i=2;i<=n;i++){
			if(a[i]-a[i-1]<=m){
				cnt++;
			}else{
				break;
			}
		}
		cout<<cnt-2*m+1<<endl;
	}
}
