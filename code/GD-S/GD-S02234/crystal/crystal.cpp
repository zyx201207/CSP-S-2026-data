#include<bits/stdc++.h>
using namespace std;
int n,m,sum,u=10000000,d,ans;
int a[100010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	for(int i=1;i<=n;i++){
		if(a[i]-sum>=0)
			u=min(a[i]-sum,u);
		else 	u=min(sum-a[i],u);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==u+sum)
			d=i;
	}
	for(int i=d-1;i>0;i--){
		m-=a[d]-a[i];
		if(m<=0)break;
		ans++;
	}
	cout<<ans+2;
	return 0;
} 
