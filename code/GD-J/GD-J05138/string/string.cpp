#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("airplane.in","string.in"stdin)
	//freopen("airplane.out","string.out"stdout)
	int a,b[100],c=0,d;
	string ci[100];
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i]>>ci[i];
		
	}
	for(int i=1;i<=a;i++){
		if(b[i]!=b[a] and ci[i]==ci[a]){
			cout<<0;
		}else{
			c++;
			break;
		}cout<<c;
		
	}
}



