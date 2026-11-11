#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	int a[n+5],p[n+5],l[n+5],l2[n+5];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	for(int q=0;q<=n;q++){
		for(int i=0;i<=n;i++){
			a[i]=p[i];
			for(int j=0;j<=i;j++){
				if(a[j]==a[i]){
					for(int g=j+1;g<=i;g++){
						a[g]=0;
					}
					i=j;
				}
			}
		}
		for(int v=0;v<=m;v++){
			l2[v]=a[v];
			for(int z=0;z<=v;z++){
				if(l2[z]==l2[v]) x=1;
			}
			if(x=0) l[v]+=1;
		}
	}
	for(int o=0;o<=m;o++){
		cout<<l[o]<<' ';
	}
	return 0;
}
