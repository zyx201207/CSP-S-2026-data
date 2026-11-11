#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
bool cmp(long long x,long long y){
	return x>y;
}
long long sum,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==n-1){
		ans=sum&a[1];
		for(int i=2;i<=n;i++){
			ans=max(ans,sum&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2&&(n<=2000||a[1]<=4)){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<a[m];
	return 0;
}
