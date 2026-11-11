#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int a[maxn];
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=-1;
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0; 
	}
	if(n==m){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans and a[i];
		}
		cout<<ans;
		return 0;
	}
	int ans=-1;
	for(int i=0;i<n;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
/*

*/
