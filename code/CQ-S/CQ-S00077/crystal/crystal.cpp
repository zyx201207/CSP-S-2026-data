#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],ans;
bool check(int x,int y){
	int res=a[y]*(y-x+1)-(sum[y]-sum[x-1]);
	//cout<<x<<" "<<y<<" "<<y*(y-x+1)<<" "<<sum[y]-sum[x-1]<<"\n";
	return res<=m;
}
int bs(int f){
	int l=1,r=f,res=1;
	while(l<=r){
		int mid=(l+r)>>1;
		//cout<<f<<" "<<mid<<"\n";
		if(check(mid,f)){
			r=mid-1;
			res=f-mid+1; 
		}
		else{
			l=mid+1;
		}
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		//cout<<sum[i]<<"\n";
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,bs(i));
		//cout<<bs(i)<<"\n";
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
