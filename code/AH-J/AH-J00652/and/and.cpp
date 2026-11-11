#include<bits/stdc++.h>
using namespace std;
long long a[200015];
long long v[200015];
long long b[200015][35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		v[i]=1;
		cin>>a[i];
		long long tmp=a[i],p=0;
		while(tmp>0){
			b[i][p++]=tmp%2;
			tmp/=2;
		}
	}
	long long ans=0;
	for(long long i=31;i>=0;i--){
		long long u=0;
		for(long long j=1;j<=n;j++){
			if(v[j]==1){
				u+=b[j][i];
				if(b[j][i]==0) v[j]=2;
			}
		}
		if(u>=m){
			ans+=(1<<i);
			for(long long j=1;j<=n;j++){
				if(v[j]==2)
					v[j]=0;
			}
		}
		else{
			for(long long j=1;j<=n;j++){
				if(v[j]==2)
					v[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}

