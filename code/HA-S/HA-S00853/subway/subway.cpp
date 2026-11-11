#include<bits/stdc++.h>
using namespace std;
long long a[10000001];
long long w[10000001];
long long x[100001];
long long y[100001];
long long k2[1000001];
long long k3[1000001];
long long m1[100001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long m,n,c,d,p;
	long long ans=0;
	long long k1;
	k1=m+2;
	long long r;
	long long t=0;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>w[1];
	}
	for(int i=1;i<=k1;i++){
		cin>>k2[i];
	}
	for(int i=1;i<=k1;i++){
		cin>>k3[i];
	}
	r=n+2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>x[i]>>y[j];
		}	
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
		if(x[i]>=y[i]){
			t=t+w[1];
			int abs=y[i]-x[i];
			abs+=k2[3]+k2[5]+k3[3];
			t=t+abs;
			}
		}
	}
	cout<<t;
	return 0;
}
