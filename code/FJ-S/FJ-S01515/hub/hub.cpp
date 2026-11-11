#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,k;
long long u[2000010],v[2000010];
long long sum=0;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(long long j=1;j<=t;j++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(abs(u[i]-v[i])<=2){
			for(int j=n;j<=n-i;j--){
				sum++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<sum<<endl;
	}
	return 0;
}
