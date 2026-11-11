#include<bits/stdc++.h>
#define int long long
using namespace std;
int qz[500005],a[500005];
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	int n,m,ans=-1;
	cin>>n>>m;
	qz[0]=0;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qz[i]=qz[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int ii=i,cr=0;
		while(cr<=m){
			cr=cr+a[i]-a[--ii];
			if(ii<=0)break;
		}
//		ii++;
//		cout<<i<<" "<<ii<<endl;
		ans=max(ans,i-ii);
	}
	cout<<ans;
}
