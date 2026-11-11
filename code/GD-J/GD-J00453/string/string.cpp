#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
signed main(){
	fastio;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int lt=1,rt=n;
	int ans=0;
	while(lt<rt){
		int x=min(a[lt],a[rt]);
		a[lt]-=x,a[rt]-=x;
		if(c[lt] != c[rt]) ans+=x;
		if(a[lt]<=0) lt++;
		if(a[rt]<=0) rt--;
	}
	cout<<ans;
	return 0;
}
