//T1 crystal
#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500050];
long long d[500050];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)d[i]=d[i-1]+a[i];
	if(n>5000){
		for(int i=n;i>0;i--){
			long long t=a[i]*i-d[i];
			if(m>=t){
				cout<<i;
				return 0;
			}
		}
	}
	//cout<<n<<" "<<m<<endl;
	//cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<endl;
	int ans=0;
	for(int i=n;i>0;i--){
		long long t=a[i]*i-d[i];
		//cout<<a[i]<<" "<<i<<" "<<d[i]<<endl;
		for(int j=1;j<=i;j++){
			//cout<<t<<endl;
			if(t<=m){
				//cout<<j<<" "<<i<<endl;
				ans=max(ans,i-j+1);
				break;
			}
			t-=a[i]-a[j];
		}
	}
	cout<<ans;
	return 0;
}
