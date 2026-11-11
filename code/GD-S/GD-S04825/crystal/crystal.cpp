#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],x=1,y=1,an,ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=2*n;i++){
		if(an<=m&&y<n){
			an+=(y-x+1)*(a[y+1]-a[y]);y++;
		}
		if(an>m){
			an-=a[y]-a[x++];
		}
//		cout<<an<<endl;
		ans=max(y-x+1,ans);
	}
	cout<<ans;
	return 0;
}//Oct31==Dec25?
