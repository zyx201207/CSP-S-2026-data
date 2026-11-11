#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200000][2],s=0,m=0;
char b[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i][1]>>b[i];
		s+=a[i][1];
		a[i][2]=s;
	}
	int x=0,y=n-1;
	for(int i=0;i<=s/2;i++)
	{
		for(int w=s;w>=s/2;w--)
	    {
		    if(i>a[x][2])
		        x++;
		    if(w<a[y][2])
		        y--;
		    if(b[x]!=b[y])
		        m++;
	    }
	}
	cout<<m;
	return 0;
}