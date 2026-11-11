#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=5e5+10,M=3e5+10,INF=0x3f3f3f3f;
int n,m,a[N],ans[M];
vector<int> desk;
bool check(int x){
	for(int i=0;i<desk.size();i++){
		if(a[i]==x) return i;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int l=i;
		int id=check(a[l]);
		if(id) {
			//while(desk.end()!=a[l]) desk.pop();
		}
		ans[i]=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[m];
	}
	return 0;
}
