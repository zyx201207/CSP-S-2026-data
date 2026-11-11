#include <bits/stdc++.h>
using namespace std;
long long a[2000050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans<<endl;
	/*if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>MAXN) MAXN=a[i];
		}
	}
	cout<<MAXN&MAXN; return 0;
	
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl; return 0;
	}
	
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long ans=a[i]&a[j];
				if(ans>MAXN) MAXN=ans;
			}
		}
		cout<<MAXN<<endl; return 0;
	}
	
	if(m==n-1){
		long long x=a[1],y=a[1],z=a[2];
		for(int i=2;i<=n-1;i++){
			x&=a[i];
		}
		for(int i=2;i<=n-2;i++){
			y&=a[i];
		}
		y&=a[n];
		for(int i=3;i<=n;i++){
			z&=a[i];
		}
		cout<<max(x,max(y,z));
	}*/
	return 0;
}
