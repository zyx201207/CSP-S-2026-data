#include<bits/stdc++.h>
using namespace std;
int n,m,a[510001],pd[510001],ans[510001],w,qp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(pd,0,sizeof(pd));
		w=0;
		for(int j=i;j<=n;j++){
			pd[++w]=a[j];
		}
		qp=w;
		for(int j=1;j<=w;j++){
			for(int k=1;k<qp;k++){
				if(pd[k]==pd[j]){
					qp=k;
					for(int o=k;o<=n;o++){
						pd[o]=0;
					}
					break;
				}
			}
		}		
		for(int k=1;k<=qp;k++){
			ans[pd[k]]++;
		}
	 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
