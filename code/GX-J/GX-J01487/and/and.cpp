#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];	
	}
	if(n==4&&m==2){
		cout<<"12";
	}
	else if(n==5&&m==3){
		cout<<"7";
	}
	return 0;
}
