#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+50;
ll n,m,tmp,a[N];
int maxx=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	if(n==1){
		cout<<1;
		return 0;
	}
	tmp=a[2]-a[1];
	for(int i=1,j=2;i<=n&&j<=n;){
		if(tmp<=m){
			j++;
			tmp+=(j-i)*(a[j]-a[j-1]);
		}else{
			i++;
			tmp-=(a[j]-a[i]);
		}
		maxx=max(maxx,j-i);
	}
	cout<<maxx;
	return 0;
}
