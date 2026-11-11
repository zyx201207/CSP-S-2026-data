#include<bits/stdc++.h>
using namespace std;
char s[1000000000];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int a;
	cin>>a;
	int c=0,z=0;
	for(int i=0;i<a;i++){
		int b;
		cin>>b;
		char d;
		cin>>d;
		for(int j=0;j<b;j++){
			s[c]=d;
			c++;
		}
	}

	for(int i=0;i<c/2;i++){
		if(s[i]!=s[c-i-1]){
			z++;
		}
	}
	cout<<z;
	return 0;
} 
