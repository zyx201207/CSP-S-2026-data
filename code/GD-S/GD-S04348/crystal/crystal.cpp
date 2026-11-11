#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9+7;
const int N=5e5+7;
int a[N];
int n,m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int res=1,cur=0;
	for(int l=1,r=1;r<=n;r++){
		cur=cur+a[r];
		while(a[r]*(r-l+1)>cur+m&&l<r){
			cur=cur-a[l++];
		}
		res=max(res,r-l+1);
	}
	cout<<res<<"\n";
	return 0;
}
