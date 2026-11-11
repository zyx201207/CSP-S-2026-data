#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int a[500010];
int sum[500010];
int f[500010];
int ans=1;
int l=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	f[1]=1;
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-l);
//		cout<<sum[i]<<"\n"; 
		if(sum[i]<=m){
			f[i]=f[i-1]+1;
		}else {
			while(sum[i]>m){
//				cout<<"tt ";
				sum[i]-=(a[i]-a[l]);
				l++;
			}
			f[i]=i-l+1;
		}
		ans=max(ans,f[i]);
//		cout<<f[i]<<" "<<l<<"\n"<<sum[i]<<"\n";
	}
	cout<<ans;
	return 0;
} 
