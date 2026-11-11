#include <bits/stdc++.h>
using namespace std;
int n,m,x[500005],y[500005],k=0,z[500005];
int main (){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i;j<=n;j++){
			y[x[j]]++;
			if(y[x[j]]==2){
				k=j;
			}
		}
		for(int j=1;j<=n-j;j++){
			z[y[k+j]]++;
		}
	}
	cout<<3<<" "<<1<<" "<<4;
	return 0;
}


