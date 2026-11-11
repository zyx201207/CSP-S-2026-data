#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],b[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int tail,q[500009];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		tail=1;
		for(int j=i;j<=n;j++){
			for(int k=1;k<tail;k++){
				if(a[j]==q[k]){
					tail=k++;
				}
			}
			q[tail++]=a[j];
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<tail;j++){
				if(q[j]==i){
					b[i]++;
				}
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
