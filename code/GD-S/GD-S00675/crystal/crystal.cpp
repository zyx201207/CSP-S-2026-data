#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500007],pre[500007];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int i=1,ans=1;
	for(int j=1;j<=n;j++){
		while(i<j&&(j-i+1)*a[j]-pre[j]+pre[i-1]>m){
			i++;
		}
		ans=max(ans,j-i+1);
	} 
	cout<<ans;
	return 0;
}
