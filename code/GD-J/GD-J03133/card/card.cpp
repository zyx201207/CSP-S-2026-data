#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,num[100005];
	cin>>n>>m;
	int a[100005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j){
				num[j+1]=a[j];
			} 
			else{
				num[j]=num[j-1]+a[j];
			}
		}
	}
	for(int i=2;i<n;i++){
		cout<<num[i]<<" ";
	}
	return 0;
} 

