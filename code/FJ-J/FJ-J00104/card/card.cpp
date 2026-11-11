#include <bits/stdc++.h>
using namespace std;
int a[500005];
int n;
int m;
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		int vis[m+5]={0};
		int v[n+5]={0};
		int p=1;

		for (int j=i;j<=n;j++){
			int x=a[j];
			for (int k=1;k<=p;k++){
				if (v[k]==x){
					p=k;
					break;
				}
			}
			v[p]=x;
			p++;
		}
		for (int k=1;k<p;k++){
			cnt[v[k]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
}

