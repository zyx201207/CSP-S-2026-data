#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			for(int i=1;i<=m;i++){
				cout<<n<<" ";
			}
		}
	}
	return 0;
	
} 
