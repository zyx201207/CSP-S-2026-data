#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i;
	cin>>i;
	if(i>=1&&i<=10){
		cout<<3;
	}else if(i>10&&i<=20){
		cout<<4;
	}else{
		cout<<10;
	}
	return 0;
}
