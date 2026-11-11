#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int vis[200005],c[50],b[50],d[50];
	long long n,m,ans;
long long yu(long long x,long long y){
	long long sum1=1,sum2=1,sum=0;
	///cout<<"sum="<<" "<<x<<" "<<y<<" ";
	while(sum1<=30){
		c[sum1++]=x%2;
		x/=2;
	}
	while(sum2<=30){
		b[sum2++]=y%2;
		y/=2;
	}
	for(int i=1;i<=30;i++){
		if(b[i]==1&&c[i]==1)d[i]=1;
		else d[i]=0;
	}
	int t=1;
	for(int i=1;i<=30;i++){
		sum+=d[i]*t;
		t*=2;
	}
	//out<<"sum="<<sum<<endl;
	return sum;
}
void nd(int x,long long sum){
	if(x>m){
		ans=max(ans,sum);
		//cout<<"ans="<<sum<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		int sum1=sum;
		vis[i]=1;
		//cout<<i<<" ";
		sum1=yu(sum1,a[i]);
		nd(x+1,sum1);
		vis[i]=0;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		vis[i]=1;
		nd(2,a[i]);
		vis[i]=0;
		}
		//for(int i=1;i<=n;i++){
		//cout<<a[i];
		//}
		cout<<ans;
	return 0;
}
