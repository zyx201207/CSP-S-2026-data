#include<iostream>
using namespace std;
int n,m,a[550000],b[550000],k[350000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int s=1;s<=n;s++){
		for(int i=s,j=1;i<=n;i++){
		for(int k=1;k<=j;k++){
			if(a[i]==b[k]){
				j=k;
			}
		}
		b[j]=a[i];
		j++;
		for(int f=1;f<=j;f++){
			k[a[f]]++;
		}
	}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
	return 0;
} 
