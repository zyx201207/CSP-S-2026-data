#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long a[1000005]={0},b[1000005]={0};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		long long n,d,t=0;
		cin>>n>>d;
		if(n<=3)cout<<'0'<<'\n';
		else{
			for(long long j=1;j<=n;j++) cin>>a[j];
			for(long long j=1;j<=n-1;j++){
				long long s=1;
				while(a[j+s]-a[j]<=d && j+s<=n){
					b[j+s]++;
					s++;
				}
			}
			for(long long j=1;j<=n;j++){
				if(b[j]==2){
					t++;
				}b[j]=0;
			}cout<<t-1<<'\n';
		}
	}
	return 0;
}
