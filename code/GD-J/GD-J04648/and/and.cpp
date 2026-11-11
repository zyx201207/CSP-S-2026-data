#include <bits/stdc++.h>
using namespace std;
long long a[200100];
int n,m;
int nn,mx=0;
int mm(int x,int y,int z){
	int k=0;
	for(int i=x;i<n;i++){
		if(y==0){
			mx=max(mx,z&i);
			return 0;
		}
		if(y=m-1){
			z=a[i];
			mm(i+1,y-1,z);
		}else{
			if(z&i<mx){
				continue;
			}
			mm(i+1,y-1,z&i);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	nn=mm(0,m-1,0);
	cout<<mx<<666;
	return 0;
}
