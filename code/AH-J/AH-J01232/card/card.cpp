#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(int i=1;i<=n;i++){
		int zhuo[500005]={0};
		for(int j=i;j<=n;j++){
			bool b=0;
			int g;
			for(int f=1;f<=n;f++){
				if(zhuo[f]==a[j]){
					b=1;
					g=f;
					break;
				}
			}
			if(b==1){
				for(int f=g;f<=n;f++){
					zhuo[f]=0;
				}
			}
			zhuo[j]=a[j];
		}
		for(int j=1;j<=n;j++){
			c[zhuo[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
