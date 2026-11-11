#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n;
long long m,a[MAXN],sum=0,ans,ans1=1,ans2=1,vis=0,s[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]) vis=1;
	}
	if(vis==0||n*m>=100000000){
		sum+=m;
		long long sum1=sum;
		long long sum2=0;
		for(int i=n;i>=1;i--){
			if(sum1/i>=a[i]){
				ans1=i;
				break;
			}else{
				sum1-=a[i];
			}
		}
		for(long long i=1;i<=n;i++){
			sum2+=a[i];
			if(sum2/i>=a[i]){
				ans2=max(ans2,i);
			}
		}
		cout<<max(ans1,ans2);
	}
	else{
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<i;j++){
				int x=s[i]-s[j-1]+m;
				if(x/(i-j+1)>=a[i]) ans=max(ans,i-j+1);
			}
		}
		cout<<ans;
	}
	return 0;
}
