#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
int c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>> n >> m;
	for(int i=1; i<=n; i++){
		cin>> a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++) b[j]=0;
		for(int j=i; j<=n; j++){
			if(b[a[i]]==0){
				b[a[i]]++;
			}
			else{
				for(int j=1; j<=m; j++) b[j]=0;
				b[a[i]]++;
			}
		}
		for(int j=1; j<=m; j++){
			if(b[j]!=0){
				c[j]++;
			}
		}
	}
	for(int i=1; i<=m; i++) cout<< c[i] <<" ";
	return 0;
}
