#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long b[100005];
long long a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long ans=0;
	//double ave=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[i]+=b[i];
	}
	long long maxx=0,sum=0;
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			maxx=0;
			sum=0;
			for(long long k=i;k<=j;k++){
				maxx=max(maxx,b[k]);
			}
			for(long long k=i;k<=j;k++)	{
				sum+=maxx-b[k];
			}
			if(sum<=m)ans=max(ans,j-i+1);
		}
	}
	cout<<ans;
	return 0;
} //Oct31==Dec25?
