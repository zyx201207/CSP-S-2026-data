#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
struct AC{
	int lth;
	char c;
}a[N];
int n;
int ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].lth>>a[i].c;
	}
	int l=1,r=n;
	while(1){
		int mi=min(a[l].lth,a[r].lth);
		if(a[l].c!=a[r].c) ans+=mi;
		a[l].lth-=mi,a[r].lth-=mi;
		if(a[l].lth==0) l++;
		if(a[r].lth==0) r--;
		if(l>=r) break;
	}
	cout<<ans<<'\n';
	return 0;	
}
