#include<bits/stdc++.h>
using namespace std;
string s;
char a[200010];
long long n,l[200010],t,x=1,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	y=n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>a[i];
	}
	while(x<y)
	{
		if(l[x]==l[y])
		{
			if(a[x]!=a[y]) t=t+l[x];
			x++;
			y--;
		}
		else if(l[x]>l[y])
		{
			if(a[x]!=a[y]) t=t+l[y];
			l[x]=l[x]-l[y];
			y--;
		}
		else 
		{
			if(a[x]!=a[y]) t=t+l[x];
			l[y]=l[y]-l[x];
			x++;
		}
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
