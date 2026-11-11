#include<bits/stdc++.h>
using namespace std;
int main(){
	long n,m,x=0;
	long a[n],b[n];
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<=x;j++){
			if(b[i]!=a[i])b[i]=a[i];
			else{
				for(int z=j;z<=x;z++)b[i]=0;
				x=j;
			}
		}
		x++;
	}
	for(int i=0;i<=x;i++)cout<<b[i];
	return 0;
}
