#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N]={0};
long long c[N]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c[n]=0;
	
	for(int i=n-1;i>=1;i--){
		c[i]=c[i+1]+(a[i+1]-a[i]);
	}
	
	int jj=n;
	if(n>=500000) {
		long long sm=0;
		//int jj=n;
		while(sm+c[jj]<=m && jj>0) {
			sm+=c[jj];
			jj--;
		}
		cout<<n-jj<<endl;
		return 0;
	}
	
	int cnt=1;
	int ans=0;
	for(int i=n;i>0;i--){
		//cout<<i<<' ';
		long long sum=0;
		if(ans>=i)break;
		int j=i-1;
		while(c[j]-c[i]<=m && j>=1 && sum+c[j]-c[i]<=m){
			sum+=(c[j]-c[i]);
			j--;
		}
		cnt=i-j;
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	
	return 0;
}

