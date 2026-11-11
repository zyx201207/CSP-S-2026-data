#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	long long b=0,x=0;
	long long c;
	cin>>c;
	for(int i=0;i<c;i++){
		int d;
		char e;
		cin>>d>>e;
		for(int i=0;i<d;i++){
			a+=e;
		}
	}
	for(int i=0;i<a.length()/2;i++){
		if(a[i]!=a[a.length()-i-1])x++;
	}
	cout<<x<<a;
	return 0;
} 
