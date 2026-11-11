#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n,m,ans,a[MAXN],b[MAXN][51],cnt[51];
struct node{
	int v,id;
}c[MAXN];
bool cmp(node x,node y){
	return x.v > y.v;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	for(int i = 1;i<=n;i++)
		for(int j = 0;j<=30;j++)
			b[i][j] = ((a[i]>>j)&1);
	for(int i = 1;i<=n;i++)
		for(int j = 0;j<=40;j++)
			cnt[j] += b[i][j];
	for(int i = 1;i<=n;i++){
		c[i].id = i;
		for(int j = 0;j<=40;j++)
			if(b[i][j] && cnt[j]>=m) c[i].v += (1<<j);
	}
	sort(c+1,c+n+1,cmp);
	ans = a[c[1].id];
	for(int i = 2;i<=m;i++) ans = (ans&a[c[i].id]);
	cout << ans;
	return 0;
} 
