#include<bits/stdc++.h>
using namespace std;
const int N=5002;
int a[N];
int main()
{
	int n,m,y[5002],js,bl=0;
	ios::sync_with_stdio(0);
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		y[i]=a[i];
		js=y[i];
		for(int j=0;j<=y[i];j++){
			bl=j;
			if(js=y[bl]){
				for(int z=0;z<=bl;z++){
					y[z]=0;
				}
			}
		}
		for(int j=1;j<=m;j++){
			
		}
	}
	return 0;
}
