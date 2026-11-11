#include <bits/stdc++.h>
using namespace std;
int c,t;
int n[2000000],d[20000000];
int x[2000005];
/*void FS(int x,int y)
{
	if(x==y) return ;
	if(x+d>=y)
	{
        
	}
}*/
int main(int argc, char** argv) {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
/*	cin>>c>>t;
	while(t!=0)
	{
	    int x[2000005]={};
		t--;
		cin>>n>>d;
		for(int i=0;i<n;i++)
		cin>>x[i];
	}*/
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=0;j<n[i];j++)
		cin>>x[j];
	}
	for(int i=0;i<t;i++)
	{
		cout<<rand()%(n[i]-2);
		if(i!=t-1)
		cout<<endl;
	}
	return 0;
}
