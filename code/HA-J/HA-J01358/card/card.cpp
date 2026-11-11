#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[1000];
	int i=0;
	cin>>a[i];
	int k=0;
	while(k<=m){
		if(k!=a[i]){
			return 1;
		}else{
			return false;
		}
	}
	cout<<m<<" "<<a<<" "<<n<<endl;
	return 0;
} 
