#include<bits/stdc++.h>
using namespace std;
char a[9000];
int n,g=0,j=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int b;
		char s;
		cin>>b>>s;
		for(int k=j;k<=j+b;j++)
			j+=b;
	}
	for(int i=0;i<j/2;i++){
		if(a[i]!=a[j-i]){
			g+=1;
		}
	}
	cout<<g;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
