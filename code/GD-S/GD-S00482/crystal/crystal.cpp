#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5,inf=1e18;
int n,m,a[N],dif[N],sum,ans;
bool B=1;
void svB(){
	for(int i=2;i<=n;i++){
		dif[i]+=dif[i-1];
		sum=dif[i]-dif[i+1]*(i-1);
		if(sum>m){
			cout<<i-1;
			return;
		}
	}
	cout<<n;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]-a[i-1]!=a[2]-a[1]) B=0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) dif[i]=a[i]-a[i-1];
	for(int i=n-1;i>=2;i--) dif[i]+=dif[i+1];
	if(B&&n>10000){
		svB();
		return 0;
	}
	for(int i=2;i<=n;i++){
		dif[i]+=dif[i-1];
		sum=dif[i]-dif[i+1]*(i-1);
		//把前面所有都变成a[i]的总花费
		if(sum<=m) ans=max(ans,i);
		else{
			int l=1;
			while(sum>m){
				sum-=a[i]-a[l];
				l++;
			}
			ans=max(ans,(i-l+1));
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7

*/
