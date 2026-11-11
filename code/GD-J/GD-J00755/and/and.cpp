#include<bits/stdc++.h>
using namespace std;
int a[200005],dp1[200005],dp2[200005];
bool f=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],dp1[i]=max(a[i],dp1[i-1]);
	dp1[0]=-1;
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(f){
				if(dp1[j-1]!=-1) dp2[j]=max(dp2[j-1],(dp1[j-1]&a[j]));
				else dp2[j]=dp2[j-1];
			}else{
				if(dp2[j-1]!=-1) dp1[j]=max(dp1[j-1],(dp2[j-1]&a[j]));
				else dp1[j]=dp1[j-1];
			}
		}
		f=(!f);
	}
	if(f) cout<<dp1[n]<<"\n";
	else cout<<dp2[n]<<"\n";
	return 0;
}
