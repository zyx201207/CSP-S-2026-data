#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxans=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=m;i<=n;i++){
		int cnt=1073741823;
		for(int j=0;j<m;j++)cnt&=a[i-j];
		maxans=max(maxans,cnt);
	}
	cout<<maxans;
	return 0;
}
