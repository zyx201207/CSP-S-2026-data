#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	for(int i=1;i<=t;i++){
		long long sum=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		for(int i=2;i<=n-1;i++){
			if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
				sum++;
			}
		}	
		cout<<sum-1<<endl;
	}
	return 0;
}
