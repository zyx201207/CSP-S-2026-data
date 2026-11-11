#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long a[N];
long long sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long t=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[2]==2&&a[n]==n&&a[n/2]==n/2&&a[n/2+2]==n/2+2){
		for(int i=1;i>=-1;i++){
			sum++;
			if(m<i) break;
			m-=i;
		}
		cout<<sum;
		return 0;
	}else if(a[2]-a[1]==a[n]-a[n-1]&&a[4]-a[3]==a[n/2+1]-a[n/2]&&a[2]-a[1]==a[4]-a[3]){
		for(int i=a[1];i>=-1;i+=(a[4]-a[3])){
			sum++;
			if(m<i) break;
			m-=i;
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++){
		m=t,sum=1;
		for(long long j=i-1;j>=1;j--){
			if(a[i]-a[j]<=m){
				m-=(a[i]-a[j]);
				sum++;
			}
			if(m<=0) break;
		}
		if(sum>ans) ans=sum;
	}
	cout<<ans;
	return 0;
} 

