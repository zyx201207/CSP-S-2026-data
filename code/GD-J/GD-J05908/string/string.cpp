#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a,b,c=0,d=0;
	string x,y;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b>>x;
		c+=b;
		for(int j=1;j<=b;j++){
			y+=x;
		}
	}
	for(int i=0;i<c/2;i++){
		if(y[i]!=y[c-i]){
			d++;
			y[i]=y[c-i];
		}
	}
	cout<<d;
	return 0;	
} 
