#include<bits/stdc++.h>
using namespace std;
int n;
string a,b;
int cnt=0;
int main(){
	freopen("string.in",stdin);
	freopen("string.out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			a=a+y;
			b=y+b;
		}
	}
	//cout<<a<<b;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i])
			cnt++;
	}
	cout<<cnt/2;
	return 0;
} 
