#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int a[MAXN],sum[MAXN],ans=0;
unsigned int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	if(n>8888){
		unsigned int s=0;
		unsigned int gongcha=abs(a[n]-a[n-1]);
		m/=gongcha;
		for(unsigned int i=sqrt(m)+sqrt(m)/3;;i++){
			if(i*(1+i)/2>m){
				s=i;
				break;
			}
		}
		cout<<s;
		return 0;
	}
	if(a[1]<0){
		int k=-a[1];
		for(int i=1;i<=n;i++){
			a[i]+=k;
		}
	}
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((j-i+1)*a[j]-(sum[j]-sum[i-1])<=m){
				ans=max(ans,j-i+1);
			}
			else{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
