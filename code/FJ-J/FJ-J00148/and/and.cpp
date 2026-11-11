#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+8;
const int MAXM=4e1+8;
int n, m, maxn, b[MAXN][MAXM], c[MAXM], a[MAXN];
bool e[MAXN], d[MAXM];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		int x=a[i], j=0;
		while (x){
			j++;
			b[i][j]=x%2;
			c[j]+=(x%2);
			x/=2;
		}
	}
	for (int i=1;i<=32;i++)if (c[i]>=m)maxn=i;
	while (maxn){
		int cnt=0, sum=0, t[MAXN]={};
		for (int i=1;i<=n;i++){
			if (!b[i][maxn]){
				if (!e[i])t[++sum]=i;
				e[i]=1;
			}
			if (e[i])continue;
			cnt++;
		}
		if (cnt>=m)d[maxn]=1;
		else for (int j=1;j<=sum;j++)e[t[j]]=0;
		maxn--;
	}
	int ans=0;
	for (int i=1;i<=32;i++)if (d[i])ans+=pow(2,i-1);
	cout << ans;
	
	return 0;
}
