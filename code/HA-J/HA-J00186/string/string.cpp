#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
struct node{
	int a;
	char c;
}q[N],a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].c;
	}
	for(int i=2;i<=n+1;i++){
		if(q[i].c==q[i-1].c){
			q[i].a+=q[i-1].a;
		}
		else{
			a[++cnt]=q[i-1];
		}
	}
	if(cnt==1){
		cout<<0<<'\n';
		return 0;
	}
	int ans=0;

	for(int l=1,r=cnt;;){
		if(l>r) break;
		int t=min(a[l].a,a[r].a);
		a[l].a-=t,a[r].a-=t;
		if(a[l].c!=a[r].c) ans+=t;
		if(a[l].a==0) l++;
		else r--;
	}
	cout<<ans<<'\n';
	return 0;
}