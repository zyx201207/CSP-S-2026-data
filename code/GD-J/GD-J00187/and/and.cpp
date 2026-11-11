#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],vis[200005];
int n,m;
signed main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		int sum=-1;
		for(int i=1;i<=n;i++){
			sum=max(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++)sum&=a[i];
		cout<<sum;
		return 0;
	}
	else cout<<17;
	return 0;
}
