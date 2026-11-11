#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
	int num;
	int a;
};

int n,m;
node a[200005];
ll ans;

bool cmp(node x,node y) {
	if(x.num!=y.num) {
		return x.num>y.num;
	}
	return x.a>y.a;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;

	for(int i=1; i<=n; i++) {
		cin>>a[i].a;
		int c=a[i].a;
		int cnt=0;
		while(c!=0) {
			c=c&(c-1);
			cnt++;
		}
		a[i].num=cnt;
	}

	sort(a+1,a+1+n,cmp);
	
	ans=a[1].a;
	for(int i=2;i<=m;i++){
		ans&=a[i].a;
	}
	
	cout<<ans;
	return 0;
}
