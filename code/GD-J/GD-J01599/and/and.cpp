#include <bits/stdc++.h>
using namespace std;
int n,m,maxn,sum;
int a[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sum=a[1]&a[2];
	for(int i=3;i<=n;i++){
		sum=sum&a[i];
	}
	if(m==1){
		cout<<maxn;
	}
	else if(m==n){
		cout<<sum;
	}
	else if(m==2){
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	return 0;
}
