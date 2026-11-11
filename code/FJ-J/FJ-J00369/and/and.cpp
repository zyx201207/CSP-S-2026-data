#include <bits/stdc++.h>
using namespace std;
long long n,m,maxs=-1,sum=0;
int len[200005];
long long z[200003];
char ejz[200003][32];
int d[35];
void dfs(int w ,int k , int sgs) {
	if (k>=m) {
		if (sgs>maxs) {
			maxs=sgs;
		}
		return ;
	}
	if (w>n) {
		return ;
	}
	for (int i=w+1; i<=n; i++) {
		int weishu=min(len[i],len[w]);
		int congnazhao=max(len[i],len[w]);
		long long x=1;
		long long  ans=0;
		int p;
		if (len[i]>len[w]){
			p=len[w];
		}
		else {
			p=len[i];
		}
		for (int j=congnazhao; j>=congnazhao-weishu+1;j--) {
			if(len[i]<len[w]){
				if (ejz[i][p]=='1' && ejz[w][j]=='1') {
					ans+=x;
				}
			}
			else {
				if (ejz[w][p]=='1' && ejz[i][j]=='1') {
					ans+=x;
				}
			}
			p--;
			x=x*2;
		}
		dfs(i+1,k+1,ans);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>z[i];
		int t=1;
		while (z[i]>0) {
			d[t]=z[i]%2;
			z[i]=z[i]/2;
			t++;
		}
		t--;
		len[i]=t;
		for (int j=t; j>=1; j--) {
			ejz[i][t-j+1]=d[j]+'0';
		}
	}
	for (int i=1;i<=n-m+1;i++){
		dfs(i,1,0);
	}
	cout<<maxs;
	return 0;
}
