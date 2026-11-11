#include<bits/stdc++.h>
using namespace std;
struct r{
	int a;
	char c;
}s[1000000];
int main(){
	int n,h=0,j=0,m=0; 
	string b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
		h+=s[i].a;
		while(s[i].a>0){
			b[j]=s[i].c;
			s[i].a--;
			j++;
		}
	}
	for(int i=0;i<h;i++){
		if(b[i]!=b[h-1]) m++;
		h--;
	}
	cout<<m;
	return 0;
}
