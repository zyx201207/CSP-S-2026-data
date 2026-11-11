#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	if(m>n){
		cout<<m-n;
		m--;
	}
	else{
		cout<<n-m;
	}
	return 0;
}
