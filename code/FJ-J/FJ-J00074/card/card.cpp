#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int p[500005];
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		int ii=1;
		for(int j=i;j<=n;j++){
			int qf=0;
			for(int k=1;k<ii;k++){
				if(qf){
					p[k]=0;
				}else if(p[k]==a[j]){
					qf=1;
					ii=k;
					p[k]=0;
				}
			}p[ii]=a[j];
			ii++;
		}for(int i=1;i<ii;i++){
			b[p[i]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;

}
