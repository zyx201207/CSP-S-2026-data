#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in",'l',stdin);
	freopen("card.out",'r',stdout);
	int n,m;
	cin>>n>>m;
	int a[n],js[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
		js[a[i]-1]+=(i+1);
	}
	for(int i=1;i<=m;i++){
		cout<<js[i]<<" ";
	}
	fclose("card.in");
	fclose("card.out");
} 
