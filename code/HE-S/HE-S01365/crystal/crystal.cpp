#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,a[100005],b[100005],mn=114514,cnt,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		//cout<<b[i]<<" ";
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		//cout<<b[i]<<" ";
		ans+=b[i];
		if(ans>=m){
			cnt=i;
			break;
		} 
		//cout<<ans<<" ";
	}
	cout<<cnt-1;
	return 0;
} 
/*5 8
-3 -1 2 2 7*/
