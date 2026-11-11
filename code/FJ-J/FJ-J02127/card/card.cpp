#include<bits/stdc++.h> 
using namespace std;
int n,m,a[10000000],c[10000000],b[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			a[j]=c[j];
			for(int x=1;x<=j-1;x++){
				if(a[j]==a[x]){
					for(int f=1;f<=x;f++){
						c[n-j+1]=a[f];
						a[f]=0;
					}
				}
			}
			for(int v=1;v<=n;v++){
				if(a[v]!=0){
					b[v]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
	   	if(b[i]>0){
	   		cout<<b[i]<<" ";
		   }
	}
	return 0;
}
