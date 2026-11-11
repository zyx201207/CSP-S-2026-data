#include <bits/stdc++.h>
using namespace std;

int a[500005],p[300005],pd[3000005];


int n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
	cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			pd[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(pd[a[j]]==0){
				pd[a[j]]=1;
			}else{
				for(int k=i;k<=j-1;k++){
					pd[a[k]]=0;
				}
				pd[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(pd[j]==1){
				p[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout <<p[i]<<" ";
	}
	return 0;
}
