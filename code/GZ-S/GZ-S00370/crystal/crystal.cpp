//GZ-S00370 北京师范大学贵阳附属中学 杨尚卿 
#include<bits/stdc++.h>
using namespace std;
int n,mx=INT_MIN,a[500050],mxn;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int cnt=0;
		for(int j=1;j<=i;++j){
			cnt+=a[i]-a[j];
		}
		if(cnt<=m){
			mx=i;
		}
	}
	for(int i=n;i>=1;--i){
		int cntt=0;
		for(int j=n;j>=i;--j){
			cntt+=a[i]-a[j];
		}
		if(cntt<=m){
			mxn=i;
		}
	}
	cout<<max(mx,mxn);
	return 0;
}

