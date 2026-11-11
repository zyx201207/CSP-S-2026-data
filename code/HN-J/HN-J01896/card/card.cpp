#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b[1000000],c[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int g=0;
	int p=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=g;j++){
			if(b[j]==a[i]){
				for(int k=j;k<=g;k++){
					b[k]=0;
				}
				break;
			} 
		}
		g++;
		b[g]==a[i];
	}
	cout<<b[g];
	return 0;
}
