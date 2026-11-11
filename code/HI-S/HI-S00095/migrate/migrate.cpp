#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
bool istrue(long long xx,long long yy){
	if(x[yy]-x[xx]<=d) return 0;
	long long sum=0;
	long long minstep=ceil((x[yy]-x[xx])*1.0/d);
	sum=yy-xx-1;
	if(sum==minstep) return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>x[i];
		for(long long i=1;i<=n-3;i++){
			if(istrue(i,i+3)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

