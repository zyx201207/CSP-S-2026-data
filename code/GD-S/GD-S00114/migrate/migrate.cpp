#include<bits/stdc++.h>
using namespace std;
long long t;
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n,m,a[200005],sum=0;
		bool p[200005];
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			p[a[i]]=1;
		}
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=m;j++){
				if(p[a[i]+j])a[i+j]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==4)sum++;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
