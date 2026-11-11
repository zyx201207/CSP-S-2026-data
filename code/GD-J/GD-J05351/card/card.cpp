#include <bits/stdc++.h>
using namespace std;
vector <int> v[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],c[500005],x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		c[i]=x;
		v[x].push_back(i);
	}
	int i=1,j=1;
	x=n;
	while(n--){
		for(int u=1;u<=x;u++){
			a[i]=c[i];
		}
		int u=0;
		while(j<=m){
			u=0;
			while(v[j][u]!=0){
				u++;
			}
			int g=u-1;
			if(g>=1){
				int u;
				for(int t=0;t<=g;t++){
					if(v[j][t]>i)u=v[j][t];
				}
				for(;u<v[j][g];i++){
					a[i]=0;
				}
			}
			j++;
		}
		for(int i=1;i<=x;i++){
			b[a[i]]++;
		}
		i++;
	}
	for(int i=1;i<=x;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
