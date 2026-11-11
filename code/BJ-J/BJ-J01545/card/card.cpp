#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500001],b[300001]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++){
		int c[500001]={},cnt=0;
		for(int j=i;j<=n;j++){
			bool e=false;
			for(int z=1;z<=cnt;z++){
				if(c[z]==a[j]){
					cnt=z;
					e=true;
					break;
				}
			}
			if(e==false){
				cnt++;
				c[cnt]=a[j];
			}
		}
		for(int i=1;i<=cnt;i++){
			b[c[i]]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		printf("%d ",b[i]);
	}
	
	return 0;
}
