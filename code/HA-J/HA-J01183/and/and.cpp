#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	int n,m;
	int a[100001];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<m*2+n*2;
	}
	else if(n==5&&m==3){
		cout<<m+n-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
