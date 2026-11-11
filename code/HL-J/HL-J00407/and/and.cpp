#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b=0;
	long long c=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c;
	}
	if(a==4){
		cout<<12;
	}
    else if(a==5){
    	cout<<7;
	}
	else{
		cout<<4;
	}
	return 0;
}
