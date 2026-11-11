#include<bits/stdc++.h> 
using namespace std;
char a[10001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,k,num=0;
	char x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		cin>>a[i];
		for(int j=0;j<m;j++)
		s+=a[i]; 
	}
	k=s.length();
	for(int i=0;i<(k+1)/2;i++){
		if(s[i]!=s[k-1-i]) 
		num++;
	}	
	cout<<num;
	return 0;}
