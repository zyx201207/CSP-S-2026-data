#include <bits/stdc++.h>
#define int long long 
using namespace std;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int num=0;
	bool id1=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			id1=0;
		}
	}
	if(id1==1){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		num=num+(a[n]-a[i]);
	}
	if(n<=5000){
		num+=a[n];
		int cnt=num,ans=0;
		for(int i=n;1<=i;i--){
			if(i!=n){
				num=cnt-(a[i+1]-a[i])*i+a[i]-a[i+1];
			}
			cnt=num;
			for(int j=0;j<=i-1;j++){
				num=num-(a[i]-a[j]);
				if(num<=m){
					ans=max(ans,i-j);
				}
			}
		}
		cout<<ans;
	}else{
		for(int i=n;1<=i;i--){
			if(num<=m){
				cout<<i;
				break;
			}else{
				num=num-(a[i]-a[i-1])*(i-1);
			}
		}
	}
	return 0;
}


