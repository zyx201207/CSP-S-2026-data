#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],add[500010],z;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		add[i]=add[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,mid,tmp;
		while(l<=r){
			mid=(l+r)>>1;
			int x=(mid-i+1)*a[mid]-add[mid]+add[i-1];
			if(x<=m){
				tmp=mid-i+1;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		z=max(z,tmp);
	}
	cout<<z;
	return 0;
}
