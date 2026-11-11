#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[m+5],x[m+5]; 
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0)x[m]=a[i];
		for(int j=0;j<0;j++){
			if(a[i]==x[j])x[m-1]=x[m],x[i]=a[i];
		}
		cout<<a[i]<<" ";
	}
	return 0;
}
