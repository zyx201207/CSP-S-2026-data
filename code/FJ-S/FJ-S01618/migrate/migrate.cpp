#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long a[2000005];
long long jl[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			jl[i]=a[i]-a[i-1];
		}
		int fla=1,flb=0;
		for(int i=3;i<=n;i++){
			if(jl[i]!=jl[i-1]){
				fla=0;
			}
			if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
				flb=1;
			}
		}
		if(fla){
			d/=jl[n];
			long long sum=0;
			for(int i=1;i<=n-d*2+1;i++){
				sum++;
			}
			cout<<sum<<endl;
			continue;
		}
		if(flb){
			long long sum=0;
			for(int i=1;i<=n;i++){
				
			}
		}
	}
	return 0;
}

