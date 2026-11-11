#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],sum[N];
int num=INT_MIN;
bool f=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=a[i]-a[i-1];
		if(sum[i]!=1) f=false;
	}
	if(f==true&&m>=1){
		cout<<n;
		return 0;
	}
//	for(int i=2;i<=n;i++) cout<<sum[i]<<" ";
	int l=2,r=2;
	while(l<=r&&r<=n){
		int ans=0;
		for(int i=l;i<=r;i++){
			ans=ans+sum[i]*(i-l+1);
		}
//		cout<<ans<<" ";
		if(ans<=m){
			r++;
		}else{
			num=max(r-l+1,num);
			l++;
			r=l;
		}
	}
	cout<<num; 
	return 0;
}
