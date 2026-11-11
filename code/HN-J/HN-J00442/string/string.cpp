#include<bits/stdc++.h>
using namespace std;
char a[200000005];
char c[200000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int b,e,s=0,d=0;
	char r;
	cin>>b;
	for(int i=0;i<b;i++){
		cin>>e>>r;
		for(int j=1;j<=e;j++){
			a[s]=r;
			s++;
		}
	}
	for(int i=0;i<b;i++){
		c[i]=a[b-i];
	}
	for(int i=0;i<b/2;i++){
		if(c[i]!=a[i])d++;
	}
	cout<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
