#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=1;
	long long m,sum;
	bool wow=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	sum=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=sum){
			wow=0;
			break;
		}
	}
	if(wow){
		m/=sum;
		for(int i=1;i*i<=m;i++)ans=max(ans,i);
		cout<<ans<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++){
		sum=0;
		long long x=a[i]-a[i-1];
		for(int j=i-1;j>=1;j--){
			a[j]=a[j]+x;
			sum+=a[j];
			//cout<<m<<" "<<sum<<" "<<i<<" "<<j<<endl;
			if(sum>m||j==1){
				ans=max(ans,i-j+1);
				break;
			}
		}
		//for(int j=1;j<=n;j++)cout<<f[j]<<" ";
		//cout<<endl;
	}
	cout<<ans;
	return 0;
} 
