#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int a[500005];
int sum;
int ans;
int t[500005];
int flag;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag=1;
	}
	if(flag==0){
		for(int i=2;i<=n;i++){
			int l=(i-1)*i/2;
			if(l<=m) ans=i;
			else{
				cout<<ans;
				return 0;
			}
		}
	}
	int d=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=d) flag=3;
	}
	if(flag!=3){
		for(int i=2;i<=n;i++){
			t[i]=(a[i]-a[i-1])*(i-1)+t[i-1];
			if(t[i]<=m) ans=i;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		t[i]=(a[i]-a[i-1])*(i-1)+t[i-1];
		if(t[i]<=m) ans=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int l=t[j]-t[i]-((a[j]-a[i])*(i-1));
			if(l<=m) ans=max(ans,(j-i+1));
		}
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?
