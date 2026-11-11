#include<iostream>
using namespace std;
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500001],b[500001],c[500001];
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			for(int k=1; k<j; k++){
				if(a[k]==a[j] && a[k]==0){
					for(int f=k; f<=j; f++)b[f]=1;
				}
			}
		}
		for(int k=i; k<=n; k++){
			if(b[k]==0) c[a[k]]++;
			else b[k]=0;
		}
	}
	for(int i=1; i<=m; i++) cout<<c[i]<<" ";
	return 0;
}