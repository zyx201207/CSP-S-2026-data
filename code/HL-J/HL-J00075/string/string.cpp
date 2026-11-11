#include<bits/stdc++.h>
using namespace std;
int a,b;
string c;
char d;
long long cnt=0;
int u;
int main(){
	freoepn("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b>>c;
		for(int i=1;i<=b;i++)
		{
			c+=d;
		} 
	}
	u=c.size()
	for(int i=1;i<=c.size()/2;i++)
	{
		if(a[i]!=u)
		{
			cnt++;
		}
		u--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdin);
	return 0;
}
