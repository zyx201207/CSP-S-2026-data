#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	long long a,b;
}s[2000010];
bool cmp(node x,node y) {
	if (x.b == y.b) return x.a > y.a;
	return x.b > y.b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		cin>>s[i].a;
		int l = 0,t = s[i].a;
		while(t > 0) {
			l += t % 2;
			t /= 2;
		}
		s[i].b = l;
	}
	
	sort(s + 1,s + n + 1,cmp);
	
	long long ans = s[1].a;
	for (int i = 2; i <= m; i++) {
		ans &= s[i].a;
	}
	cout<<ans;
	return 0;
}
