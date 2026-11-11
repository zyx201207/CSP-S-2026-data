#include <iostream>
#include <algorithm>
using namespace std;

int n,m,ans1,ans2;
int num[200005];

int func(int x) {
	int cnt;
	while (x!=0) {
		if (x&1==1) cnt++;
		x>>=1;
	}
	return cnt;
}

bool cmp(int a,int b) {
	int x=func(a);
	int y=func(b);
	return (x==y)?a>b:x>y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>num[i];

	sort(num+1,num+n+1,cmp);
	ans1=num[1];
	for (int i=1; i<=m; i++) ans1&=num[i];

	sort(num+1,num+n+1,greater<int>());
	ans2=num[1];
	for (int i=1; i<=m; i++) ans2&=num[i];

	cout<<max(ans1,ans2)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
