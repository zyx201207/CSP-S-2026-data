#include<bits/stdc++.h>
using namespace std;
int m,s=0,h=0;
int a[200002];
char b[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<m;i++)
	{
	   h=h+a[i];
	}
	h=h-1;
	int i=0,y=m-1,i1=0,c=0,c1=0;
    while(i=h)
    {
    	if(c>=a[i1])
		{
			i1++;
			c=0;
		} 
		else c++;
		if(c1>=a[y])
		{
			y--;
			c1=0;
		}
		else c1++;
		if(b[i1]!=b[y]) s++;
		i++;
		h--;
	}
	
	cout<<s;
	return 0;
}