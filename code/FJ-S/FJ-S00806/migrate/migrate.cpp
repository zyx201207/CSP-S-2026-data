#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

int c,t;
int n;ll d;
ll x[305];
ll sum=0,ans=0x7f7f7f7f7f7f7f7f;
int cnt=0,cnt2=0;

void dfs(int I,int y){
	if (I==y){
		if (sum==ans) ++cnt;
		else if (sum<ans){ans=sum;cnt=1;}
		return;
	} for (int i=I+1;i<=y;++i)
		if (x[i]-x[I]<=d){++sum;dfs(i,y);--sum;}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i=1;i<=n;++i)
			cin >> x[i];
//		if (c==11 or c==12){
//			if (d<2*(x[2]-x[1])) cout << "0\n";
//			else cout << n-3 << '\n';
//			continue;
//		}
		for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j){
			ans=0x7f7f7f7f7f7f7f7f;
			sum=0;cnt=0;dfs(i,j);
			if (cnt==2) ++cnt2;//cout << i << ' ' << j << '\n';
		} cout << cnt2 << '\n';cnt2=0;
	} return 0;
}
