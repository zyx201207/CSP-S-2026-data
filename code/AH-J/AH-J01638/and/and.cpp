#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,nn=0;
	long long maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==n){
		nn=a[1];
		for(int i=2;i<=n;i++){
			nn&=a[i];
		}
		cout<<nn;
		return 0;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	long long ans=0;
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}
