#include<bits/stdc++.h>
using namespace std;
string a="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long l=0;
	for(int _=0;_<n;_++){
		int x;
		char y;
		cin>>x>>y;
		l+=x;
		for(int _1=0;_1<x;_1++)
			a+=y;
	}
	long long cnt=0;
	for(long long _=0;_<l/2;_++)
		if(a[_]!=a[l-_-1])cnt++;
	cout<<cnt<<endl;
	fclose(stdin),fclose(stdout);
	return 0;
}