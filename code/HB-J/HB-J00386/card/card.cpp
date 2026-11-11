#include <bits/stdc++.h>

using namespace std;

#define N 500010

int n,m,a[N];
int ans[N],p[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int r=0;
		for(int j=i;j<=n;j++){
			int num=a[j];
			for(int k=1;k<=r;k++){
				if(p[k]==num){
					r=k-1;break;
				}
			}
			p[++r]=num;
		}
		for(int j=1;j<=r;j++){
			ans[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
