#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int a[100000000];
string s[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string b[100000];
	cin>>n;
	int add=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		add+=a[i];
	}
	int ss=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=a[i];j++){
			s[ss]=b[i];
			ss++;
		}
	}
	int js=0,cz=0;
	while(add/2!=0){
		if(s[cz]!=s[add]){
			js++;
		}
		cz++;
		add--;
	}
	cout<<js;
	return 0;
}
