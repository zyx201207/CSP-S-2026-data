#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int u=1,v=0,w=0;
		b[i]=a[i]-a[i-1];
		for(int j=i-1;j>=1;j--){
			v+=b[j];
			if(w+v<=m){
				w+=v;
				u++;
			}
			else{
				break;
			}
		}
		ans=max(ans,u);
	}
	cout<<ans;
	return 0;
}
