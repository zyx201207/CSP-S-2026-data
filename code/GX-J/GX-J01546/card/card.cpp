#include<iostream>

using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[500005],b[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<i;j++){
			if(a[j]==a[i]){
				for(int z=j;z<i;z++)
				 a[z]=0;
			}
		}
	}for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[n]==i)
				b[i]++;
		}
	}
	for(int p=2;p<=n;p++){
		for(int i=p;i<=n;i++){
			for(int j=p;j<i;j++){
				if(a[j]==a[i]){
					for(int z=j;z<i;z++)
					a[z]=0;
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=p;j<=n;j++){
				if(a[n]==i)
					b[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[m]<<" ";
	}
	return 0;
}
