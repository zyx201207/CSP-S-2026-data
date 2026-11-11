#include<iostream>
using namespace std;
const int N=1e4;
int n,m,a[N][N],ans[N],maxx=-1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[1][i];
		for(int j=1;j<=i;j++) a[j][i]=a[1][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<j;k++){
				if(a[k][j]==a[i][j]){
					for(int l=k;l<=j;l++){
						a[l][j]=0;
					}
				}
			}cout<<a[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]>maxx) maxx=a[i][j];
			if(a[i][j]!=0) ans[a[i][j]]++;
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=1;i<=maxx;i++) cout<<ans[i]<<" ";
	return 0;
}
