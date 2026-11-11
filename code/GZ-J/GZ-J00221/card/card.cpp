//GZ-J00221  ¿Ó È∫≠
#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n;
int m;
int a[N],ans[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;//Trick||Treat!
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				a[j]=b[j];
				//4 3 1 2 1 3
			}
			int x=1,t;
			for(int j=i;j<=n;j++){
				for(int k=i;k<=n;k++){
					if(a[k]==a[j]){
						t=j;
						x=0;
						break;
				 	}
				 	if(!x){
						for(int j=t;j<i;j++){
							cout<<a[j];
							a[j]=0;

						}
					}
				}
			}

			for(int j=0;j<=m;j++){
				if(a[j])
				ans[a[j]]++;
			}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
