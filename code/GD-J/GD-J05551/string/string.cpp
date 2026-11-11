#include<iostream>
#include<cstdio>
#include<String.h>
using namespace std;
string s,c;
int a[100100],n,t=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[t]=c[i];
			t++;
			cout<<s[t];
		}
	}
	t=0;
	int w=s.size();
	for(int i=0;i<w/2;i++){
		if(s[i]!=s[w-i]){
			t++;
		}
	}
	cout<<t;
}
