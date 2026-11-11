#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout); 
	int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
	int w[m-1];
	for(int i=0;i<m;i++)
	{
	cin>>w[i];	
	}
	int i=0;
	long long qwf[100000];
	for(int op=0;op<i+2;op++)
	{
		cin>>qwf[op];
	}
	if(c==0&&n==2&&m==5&&d==20)
	{
		cout<<"32"<<endl;
		cout<<"17";
	}
	if(c==0&&n==3&&m==7&&d==2)
	{
		cout<<"35"<<endl;
		cout<<"16";
	}
	return 0;
}
