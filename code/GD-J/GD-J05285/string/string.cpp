#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	long long data=0,l;
	string c;
	cin>>c;
	l=c.length(); 
	for(int i=0;i<=l/2;i++)
	  if(c[i]!=c[l-1-i])
	    data++;
	cout<<data;		
	return 0;
} 
