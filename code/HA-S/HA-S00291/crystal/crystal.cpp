#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],sum[N];
long long n,m,t,temp;
long long ans=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	temp=a[n]-a[n-1];
	
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=temp) t=1;
	}
	
	for(int i=2;i<=n;i+=temp){
		sum[i]+=sum[i-1]+i;
	}
	sum[1]=temp;
	
	if(t==0){
		for(int i=1;i<=n;i++){
			if(sum[i]>=m){
				cout<<1+i<<endl;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--){
		long long t=1,sum=0;
		for(int j=1;j<i;j++){
			if(sum+a[i]-a[i-j]<=m&&i-j>0){
				sum+=a[i]-a[i-j];
				t++;
			}
			else{
				break;
			}
		}
		ans=max(ans,t);
	}
	cout<<ans<<endl;
	return 0;
}

