#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans,sum;
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,x=m;
	sum=1;
	for(int i=2;i<=n;i++){
		x-=sum*(a[i]-a[i-1]);
		sum++;
		while(x<0){
			x+=a[i]-a[l];
			sum--;
			l++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
/*
5 8
-3 -1 2 2 7

*/
