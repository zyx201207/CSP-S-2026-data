#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m,a[500000],nl=0,min;
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<n;x++){
		if(a[x]<a[x+1]){
			a[x]=min;
			a[x]=a[x+1];
			a[x+1]=min;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
