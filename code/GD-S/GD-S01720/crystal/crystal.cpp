#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long mx=1;
int t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	long long a[n+5],ans[n+5];
	bool h=true;
	bool g=true;
	for(int i=1;i<=n;i++){
		ans[i]=0;
		cin>>a[i];
		if(i*(i+1)/2<=m){
			t=i+1;
		}
		if(h&&a[i]!=i)h=false;
		if(g&&a[i]!=i*(i+1)/2)g=false;
	}
	if(h){
		cout<<t;return 0;
	}
	if(g){
		long long res=0,cnt=0;
		for(int i=2;i<=n;i++){
			if(res+i<=m){
				res+=i;
			}else{
				cnt=i-1;
				break;
			}
		}
		cout<<cnt;return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+2;j<n;j++){
			if(a[j]<a[i]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=2;i<=n;i++){
		ans[i]++;
		long long ansm=m;
		for(int l=i-1;l>=1;l--){			
			if(a[i]-a[l]<=ansm){
				ansm-=(a[i]-a[l]);
				ans[i]++;
				mx=max(ans[i],mx);
			}else{
				break;
			}
		}
	}cout<<mx;
	return 0;
}

