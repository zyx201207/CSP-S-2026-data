#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>m){
			return 0;
		}
	}
	int b[n]={0};
	int cut=0;
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
		if(a[i]>a[i+1]){
			b[i]=a[i];
			cut+=i;
			cout<<cut<<" ";
			break;
		  }
		} 	
	}
	return 0;
}
