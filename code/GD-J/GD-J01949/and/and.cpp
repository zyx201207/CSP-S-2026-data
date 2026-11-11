#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],b[200010];
long long ma=-1e9;
void dfs(int x,int y){
	if (x==n+1){
		if (y!=m) return;
		long long yv=1;
		bool flag=0;
		for (int i=2;i<=n;i++)
			if (a[i]==1)
				if (flag==0){
					yv=b[i];
					flag=1;
				}
			else yv=yv & b[i];
		ma=max(ma,yv);
		return;
	} 
	a[x]=0;
	dfs(x+1,y);
	if (y<m){
		a[x]=1;
		dfs(x+1,y+1);
	}
	return; 
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> b[i];
	dfs(1,0);
	cout << ma;
	return 0;
} 
