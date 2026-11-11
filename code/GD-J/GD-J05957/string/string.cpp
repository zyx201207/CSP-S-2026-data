#include<bits/stdc++.h>
using namespace std;
int main(){
	char a,b;
	long n,m,sum=0,x=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>b;
		for(int j=0;j<m;j++){
			a[x]=b;
			x++;
		}
		sum+=m; 
	}
	cout<<sum;
	return 0;
}
