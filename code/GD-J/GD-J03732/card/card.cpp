#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 10,maxm = 3e5 + 10;
int a[maxn],nxt[maxn],val[maxn];
int p[maxm];
int ans[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",a+i);
		nxt[p[a[i]]] = i;
		p[a[i]] = i;
		val[i] = 1;
	}
	for(int i = 1;i <= n;i++)
		if(nxt[i])val[nxt[i]] += val[i];
		else{
			ans[a[i]] += val[i];
			val[i+1] += val[i];
		}
	for(int i = 1;i <= m;i++)
		printf("%d ",ans[i]);
}
