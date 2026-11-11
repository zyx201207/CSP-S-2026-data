#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,y;
	int a[1000]={0};
	int z=1;
	int k[100]={0};
	int h=0,g=0;
		int o=2;
		int l=4,j=1;
	while(z<=m){
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			cin>>a[i];
		}
		int d=a[x];
		while(o>1){
			for(int i=1;i<=a[l];i++){
				if(l>=x){
					o=0;
					break;
				}
				int e=0;
				if(a[i]<=0){
					e=a[l]+a[i];
				}
				else{
					e=a[l]-a[i];
				}
				if(e%2!=0){
					j++;
				}
				l+=1;
				i--;
			}
		}
		l=4;
		o=2;
		k[z]=j;
		z++;
	}
	for(int i=1;i<=z-1;i++){
		cout<<k[i]<<endl;
	}
	return 0;
}
