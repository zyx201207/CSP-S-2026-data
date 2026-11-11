#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=500005;
int a[N],cnt[N],nums[N];
queue<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cout<<n<<" ";
	return 0;
}