#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int z=0;z<n;z++){
		int t=z;
		cin>>a[z];
		int u=m;
		for(int i=0;i<z;i++){
			u-=a[z]-a[i];
		}
		if(u<0){
			cout<<t;
			break;
		}
	}
	
	
	return 0;
} 
