#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,l=0;
	freopen("string.in","r",stdin);
	cin>>n;
	int a[n];
	string c,s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c;
		for(int j=0;j<a[i];j++)	s+=c;
		l+=a[i];
	}
	int count=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i])	count++;
	}
	
	freopen("string.out","w",stdout);
	cout<<s;
	cout<<count;
	fclose(stdout);
}
