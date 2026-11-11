#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,inf=0x3f3f3f3f;
int n,m;
int a[N];
int last;
int g[N];
int G[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n >>m;
	for (int i=1;i<=n;i++)
		cin >>a[i];
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			last=j;
			if(g[j-1]!=a[j]) g[j]=a[j];
		}
		for (int j=i;j<=m;j++)
			G[j]++;
	}
	for (int i=1;i<=m;i++)
		cout <<G[i] <<" ";
	return 0;
}
