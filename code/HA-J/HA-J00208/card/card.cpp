#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans[300001],now[500001];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			now[j]=a[j];
			for(int x=i; x<j; x++) {
				if(now[x]==now[j]) {
					for(int q=x; q<j; q++) {
						now[q]=0;
					}
					break;
				}
			}
		}
		for(int j=i; j<=n; j++) {
			ans[now[j]]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
