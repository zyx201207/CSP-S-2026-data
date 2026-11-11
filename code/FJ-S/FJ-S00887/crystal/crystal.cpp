#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[500005];
int b[500005]; //b[i]= a[i]->a[i+1]  
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) b[i]=a[i+1]-a[i];
	int ans=0,l=1,r=1;
	int tot=b[1];//b[1]+b[2]+b[3]...
	int sum=b[1];//b[1]x1+b[2]x2+b[3]x3...
	while (l<=r&&r<n-1){
		if (r<n-1&&sum+b[r+1]*(r-l+2)<=m){
			r++;
			tot+=b[r];
			sum+=b[r]*(r-l+1); 
		}
		else if (r<n-1&&b[r+1]*(r-l+1)<=tot){
			sum=sum-tot+b[r+1]*(r-l+1);
			tot=tot-b[l]+b[r+1];
			l++,r++;
		}else if (r<n-1&&sum-tot+b[r+1]*(r-l+1)<=m){
			sum=sum-tot+b[r+1]*(r-l+1);
			tot=tot-b[l]+b[r+1];
			l++,r++;
		}else l=r+1,r=r+1,tot=b[r+1],sum=b[r+1];
		ans=max(ans,r-l);
	}
	cout<<ans+2;
	return 0;
}

