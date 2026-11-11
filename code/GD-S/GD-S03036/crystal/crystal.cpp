#include<bits/stdc++.h>
using namespace std;
#define int long long
#define filename "crystal"
const int MAXN=500005;
int n,m;
int a[MAXN];

signed main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int d=a[2]-a[1];
	int cnt=m/d;
	cout<<cnt<<endl;
	
	
}
