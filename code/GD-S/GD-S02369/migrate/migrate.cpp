#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		long long n,d,sum;
		long long l[200005],s;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>l[i];
		}
		s=l[2]-l[1];
		long long ls=d/s;
		for(long long i=1;i<=n-ls-1;i++){
			for(long long j=i+ls+1;j<=n;j++){
				if((j-i)%ls!=0){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
