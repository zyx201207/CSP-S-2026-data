#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long a[500005],m,tot=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1;
	for(int i=1;i<=n;i++){
		while((i-l)*(a[i]-a[i-1])>m-tot){
			tot-=a[i-1];tot+=a[l];
			l++;
		}
		tot+=(i-l)*(a[i]-a[i-1]);
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
