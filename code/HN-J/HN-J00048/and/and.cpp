#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans,a[200005],sum=1048575;
int maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum&=a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		maxn=-1;
		for(int i=1;i<=n;i++){
			ans=1048575;
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans&=a[j];
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
