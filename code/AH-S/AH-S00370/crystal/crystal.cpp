#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool f=1;
	int d=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		if(i==1){
			continue;
		}
		if(i==2){
			d=a[2]-a[1];
			continue;
		}
		if(f&&d!=a[i]-a[i-1]){
			f=0;
		}
	} 
	if(f){
		int ans=1;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i]*i-s[i]<m){
				ans=i;
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=20000){
		int ans=1;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			int c=0,j;
			for(j=i-1;j>=1;j--){
				if(c+a[i]-a[j]<=m){
					c+=a[i]-a[j];
				}
				else{
					break;
				}
			}
			ans=max(ans,i-j);
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}
