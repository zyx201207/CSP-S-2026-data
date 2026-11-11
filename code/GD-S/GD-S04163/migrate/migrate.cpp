#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long a[N];
long long sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,m;
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>m;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			if(a[2]-a[1]<=m) cout<<0;
			else cout<<n-3;
			cout<<endl;
		}
		else{
			for(int i=1;i<=n-3;i++){
				if(a[i+3]-a[i]>m&&a[i+1]-a[i]<=m&&a[i+3]-a[i+1]<=m&&a[i+2]-a[i]<=m&&a[i+3]-a[i+2]<=m) sum++;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
} 

