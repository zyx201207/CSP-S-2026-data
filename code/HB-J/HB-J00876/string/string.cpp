#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005],ans=0,m;
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	int l=1,r=m,cnt1=1,cnt2=n;
	while(l<=m/2&&r>=m/2){
		l+=min(a[cnt1],a[cnt2]);
		r-=min(a[cnt1],a[cnt2]);
		if(c[cnt1]!=c[cnt2]) 
			ans+=min(a[cnt1],a[cnt2]);
		if(a[cnt1]>a[cnt2]){
			a[cnt1]-=a[cnt2];
			cnt2--;
		}
		else if(a[cnt1]<a[cnt2]){
			a[cnt2]-=a[cnt1];
			cnt1++;
		}
		else{
			cnt1++;cnt2--;
		}
	}
	cout<<ans;
	return 0;
}
