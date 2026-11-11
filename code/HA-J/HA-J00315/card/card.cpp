#include<bits/stdc++.h>
using namespace std;
int a[50010],b[50010],c[50010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[50010],b[50010],c[50010];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		int zhb=1;
		for(int i=j;i<=n;i++){
			bool flag=true;
			for(int k=1;k<=zhb-1;k++){
				if(b[k]==a[i]){
					flag=false;
					zhb=k+1;
					break;
				}
			}
			if(flag){
				b[zhb]=a[i];
				zhb++;
			}
		}
		for(int i=1;i<zhb;i++){
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
