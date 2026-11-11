#include <bits/stdc++.h>
using namespace std;
int z[200005];
string y[200005];
int main()
{
	long long n,m,a,b=0,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		c=a;
		b=0;
		while(c!=0){
			y[b]=c%2;
			c/=2;
			b++;
			
		}
		cout<<y<<endl;
	}
	return 0;	
} 
