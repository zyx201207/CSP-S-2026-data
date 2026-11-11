#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[0]=0;
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(long long i=2;i<=n;i++){
		int j=i-1,sum=0;
		while(sum<=m){
			sum+=b[i]-b[j];
			ans=max(ans,i-j+1);
			j--;
			if(j==0) break;
		}
	}
	cout<<ans;
	return 0;
}
