#include<bits/stdc++.h>
#define MAXN 5000000
using namespace std;

long long m,n,ans=0,dx,l=1,r=1;
long long a[MAXN],dad[MAXN]; 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		dad[i]=a[i]-a[i-1]+dad[i-1];
		if(dx<=m){
			dx+=dad[i];
			r++;
		}else{
			dx-=dad[l];
			l++;
		}
		ans=max(r-l+1,ans);
//		cout<<dx<<" "<<ans<<" "<<l<<" "<<r<<endl;
	}
	cout<<ans;
	return 0;
} 

