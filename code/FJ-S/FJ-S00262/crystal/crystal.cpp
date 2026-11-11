#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int sum,cnt,ans;
int c,z;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	c=a[2]-a[1];
	int f=0;
	for(int i=3;i<=n;i++){
		if(c!=(a[i]-a[i-1])){
			f=1;
			break;
		}
	}
	if(f==0){
		z=m/c;
		while(z>0){
			z-=(++cnt);
			ans++;
		}cout<<ans;
		return 0;
	}ans=0;
	for(int k=1;k<=n;k++){
		sum=0;
		cnt=0;
		int vis=0;
		for(int i=k;i>=1;i--){
			sum+=a[k]-a[i];
			if(sum>m){
				ans=max(ans,cnt);
				vis=1;
				break;
			}else{
				cnt++;
			}
		}if(vis==0)ans=max(ans,cnt);
	}cout<<ans;
	return 0;
}
