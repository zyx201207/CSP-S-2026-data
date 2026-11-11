#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		int need,aans;
		need=aans=0;
		aans++;
		for(int j=i-1;j>=1;j--){
			need+=a[i]-a[j];
			if(need>m)break;
			aans++;
		}
		ans=max(aans,ans);
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25? 
