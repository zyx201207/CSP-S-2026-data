#include<bits/stdc++.h>
using namespace std;
long long w[500005];
long long a[500005];
long long t[500005];
long long x[500005];
long long y[500005];
long long k[550];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p,sum=0;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		sum+=w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			sum+=t[i];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x[i]>>y[i];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
