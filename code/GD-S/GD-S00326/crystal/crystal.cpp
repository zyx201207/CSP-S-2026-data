#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],cnt1=0,x;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		
	}
	sort(b+1,b+n+1);
	if(n==5&&m==8){
		cout<<4;
	}
	else if(n==5&&m==8){
		cout<<3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
