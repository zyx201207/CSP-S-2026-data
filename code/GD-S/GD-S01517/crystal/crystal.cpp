#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],maxx,l,noww;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1;
	for(int i=1;i<=n;i++){
		noww+=(i-l)*(a[i]-a[i-1]);
		while(noww>m){
			noww-=a[i]-a[l];
			l++;
		}
		maxx=max(maxx,i-l+1);
	}
	cout<<maxx;
	return 0;
}
