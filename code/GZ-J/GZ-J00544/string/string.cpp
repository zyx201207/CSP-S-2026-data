//GZ-J00544，秦语涵，贵阳云岩区中天中学 
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n*2;i++){
		cin>>s[i];
	}
	char a[105];
	for(int i=0;i<n*2;){
		int b=1;
		for(int j=s[i];j>0;j--)a[b]==s[i+1];
		i+=2;
		b++;
	}
	char c[105];
	for(int i=n-2;i>=0;){
		int b=1;
		for(int j=s[i];j>0;j--)a[b]==s[i-1];
		i-=2;
		b++;
	}
	return 0;
}
