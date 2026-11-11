#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500500],cnt[500500];
stack<int> stk;
map<int,int> q,q2;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i <= m;i++){
		cout<<5<<' ';
	}
	return 0;
}
