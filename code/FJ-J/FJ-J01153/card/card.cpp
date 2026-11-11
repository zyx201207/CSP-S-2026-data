#include<bits/stdc++.h>
using namespace std;
const int n_2=5*100000;
int a[n_2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int chu=a[j];
			for(int k=1;k<=m;k++){
				if(a[k]!=chu){
					for(int y=1;y<=m;y++){
						a[y]=a[y+1];
						chu=a[m];
					}
				} 
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
