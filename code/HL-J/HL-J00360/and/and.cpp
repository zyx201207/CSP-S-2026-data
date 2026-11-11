#include<bits/stdc++.h>
using namespace std;
long long a[200005];
const long long INF=LONG_LONG_MAX;
int main(){//40
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	long long ans=INF;
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=min(ans,a[i]);
		}
	}else if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
	}else if(m==2){
		ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;i<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else{
		sort(a+1,a+n+1);
		ans=a[n-1];
	}
	cout<<ans;
	return 0;
} 
