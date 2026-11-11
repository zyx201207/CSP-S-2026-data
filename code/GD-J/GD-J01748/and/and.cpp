#include<bits/stdc++.h>
using namespace std;

int a[200005],b[200005],c[200005],n,m,mx=-1,k=1;
void dfs(int x){
	if (x>m) {
		int sum=c[1];
		for (int i=2 ; i<k ; i++){
			sum=(sum&c[i]);
		}
		mx=max(mx,sum);
		return ;
	}
	for (int i=1 ; i<=n ; i++){
		if (b[i]) continue ;
		c[k]=a[i];
		k++;
		b[i]=1;
		dfs(x+1);
		b[i]=0;
		k--;
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1 ; i<=n ; i++) cin>>a[i];
	dfs(1);
	cout << mx;
	return 0;
}
