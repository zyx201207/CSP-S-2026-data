#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,s1,c2,s2;
	char a,b;
	cin>>c1>>s1>>c2>>s2;
	if (c1=c2){
		cout<<1;
		if (s1=s2){
			cout<<1;
		}else cout<<000;
	}else cout<<00001;
	return 0;
}
