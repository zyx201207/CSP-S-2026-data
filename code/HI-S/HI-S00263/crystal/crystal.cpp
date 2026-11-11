#include<bits/stdc++.h>
using namespace std;
int s(int z){
	if(z>=0){
		return z;
	}else{
		return z*-1;
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m,a[500003],d;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=2;i++){
		d += a[i];
	}
	d = s(d);
	cout<<d<<endl;
	
	return 0;
} 
