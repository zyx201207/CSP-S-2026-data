#include <bits/stdc++.h>
#define int long long
#define fr first
#define se second
#define pii pair<int,int>
#define vt vector
#define mkp make_pair
#define elainya_stars return
using namespace std;
const int inf=INT_MAX;

const int N=5e5+7;
const int lg_N=21;
int n,k,mx=0;
int v[N]={0};
int check(int l,int r){
	int maxx=0;
	for(int i=l;i<=r;i++) maxx=max(maxx,v[i]);
	int s=0;
	for(int i=l;i<=r;i++) s+=maxx-v[i];
	if(s>k) elainya_stars 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> v[i];
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) if(check(i,j)) mx=max(mx,j-i+1);
	cout << mx << endl;
	elainya_stars 0;
}
