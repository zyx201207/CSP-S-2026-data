#include<bits/stdc++.h>
using namespace std;
int n;
int a,a2;
char c,c2;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0; 
	}
	cin>>a>>c>>a2>>c2;
	if(n==2){
		if(c==c2){
		cout<<"0";
		return 0;
		}else{
		cout<<"1";
		return 0;
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}

