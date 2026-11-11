#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int a[1010101];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=-1e6;i<=1e6;i++){
		int x=m;
		int sum=0;
		for(int k=n;k>=1;k--){
			if(a[k]>i)continue;
			x=x-i+a[k];
			if(x>=0){
				sum++;
			}else{
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}