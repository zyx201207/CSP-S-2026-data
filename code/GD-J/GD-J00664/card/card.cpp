#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n+3];
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		int a[n-i+3],x[n-i+3]={0};
		int flag=0,ly=1;
		for(int j=i; j<=n; j++){
			for(int k=i; k<=n; j++){
				if(x[k]==a[j]){
					flag=1;
				}
			}
			if(!flag){
				x[ly]=a[j];
			}
		}
	}
	return 0;
}
