#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(a>=b){
	cout<<(a+c)/2;
	}else{
		cout<<b-a+1; 
	}
	return 0;
}
