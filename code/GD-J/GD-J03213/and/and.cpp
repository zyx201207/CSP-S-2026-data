#include <bits/stdc++.h>
using namespace std;
const int N=200005;
struct node{
	long long a,i;
}b[N];
bool cmp(node a,node b){
	if (a.a!=b.a){
		return a.a>=b.a;
	}else{
		return a.i<b.i;
	}
}
long long a[N];
vector <long long> xn[35];
bool vis[35][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for (long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		long long base=1,cnt=0;
		while (a[i]>=base){
			if ((a[i]&base)!=0){
				xn[cnt].push_back(i);
			}
			base*=2;
			cnt+=1;
		}
	}
	for (long long i=34;i>=0;i--){
		if (xn[i].empty()) continue;
		if (xn[i].size()>=m){
			for (auto now:xn[i]){
				vis[i][now]=1;
			}
		}
	}
	for (long long i=1;i<=n;i++){
		long long cnt=0;
		for (long long j=34;j>=0;j--){
			if (xn[j].empty() || xn[j].size()<m) continue;
			if (vis[j][i]){
				cnt+=1;
			}else{
				break;
			}
		}
		b[i].a=cnt;
		b[i].i=i;
	}
	sort(b+1,b+1+n,cmp);
	long long ans=a[b[1].i];
	for (long long i=2;i<=m;i++){
		ans=(ans&a[b[i].i]);
	}
	cout << ans;
	return 0;
}
// 1111 1100 1100 0011
// 1111 1100 1100
// 1111 1100 1100
// 1111 0011
// 1111 0011
