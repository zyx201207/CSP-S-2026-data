#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r" ,stdin);
	freopen("card.out","w" ,stdout);
	int n,m,x[10000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		x[i]=m;
		if(x[i]=i) x[n]=1;
	}
	for(int i=0;i<n;i++){
		cout<<x[i]<<" ";
	}
	
	return 0;
}
