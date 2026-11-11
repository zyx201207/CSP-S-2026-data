#include<bits/stdc++.h>
using namespace std;
int a[500001];
int p[500001],num[300001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>p[i];
	int xb;
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;i++){
			for(int j=i;j<=xb;j++){
				if(a[j]==p[i])xb=j;
				else{
					a[xb]=p[i];
					xb++;
				}
			}
		}
		for(int i=1;i<=xb;i++)num[a[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<num[i]<<' ';
	return 0;
}
