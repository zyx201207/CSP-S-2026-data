//GZ-J00403 ∂≠≤©”Ó 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300010],b[300010],ans[300010];
/*
4 3
1 2 1 3
*/
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p;
	for(int i=1;i<=n;i++){
		p=0;
		for(int j=i;j<=n;j++){
			int id=upper_bound(b+1,b+p+1,a[j])-b;
			if(b[id]==a[j]){
				p=id;
			}
			else{
				b[++p]=a[j];
			}
		}
		for(int i=1;i<=p;i++){
			ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}


