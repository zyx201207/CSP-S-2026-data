//AC++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<climits>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#define int long long
using namespace std;
int n,m;
int maxn=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++) cin>>x,maxn=max(maxn,x);
	cout<<maxn;
	return 0;
}
