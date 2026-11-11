#include <iostream>
using namespace std;	
string a;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,step=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;
		string b;
		cin>>m>>b;
		for(int j=1;j<=m;j++)
		{
			a+=b;
		}
	}
	int l=a.size();
	string x,y;
	for(int i=0;i<l;i++)
	{
		x+=a[i];
		y+=a[l-i-1];
	}
	for(int i=0;i<l/2;i++)
	{
		if(x[i]!=y[i])step++;
	}
	cout<<step;
	return 0;
} 
