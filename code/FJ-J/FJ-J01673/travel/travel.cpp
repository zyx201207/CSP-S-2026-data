#include<bits/stdc++.h>
using namespace std;
int n,m;
char n1[8],m1[8];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>n1[1]>>n1[2]>>n1[3]>>m>>m1[1]>>m1[2]>>m1[3];
    if(n==m)
    {
    	cout <<"1"; 
	}
	else{
		cout<<"0";
	}
	int sumn=n1[1]*10+n1[2]; 
	int summ=m1[1]*10+m1[2]; 
	if(sumn==summ)
	{
	cout<<"1";
	}
	else
	{
		cout<<"0"; 
	}
	bool b=0,a=0;
	char q[7]={'A','B','C','F','D'};
	for(int i=1;i<=4;i++)
	{
		if(n1[3]==q[i]&&n1[3]+m1[3]!='D'+'C')
		{
			if(n1[3]=='A'+'C')
			{
				a=1;
				b=1;
				break;
			}
			if(m1[3]==q[i-1]||m1[3]==q[i+1])
		{
			a=true;
			break;
		}
		}
	}
	if(sumn==summ)
    cout<<a;
	else
	 cout<<a;
	 if(b!=1)
	 {
	 	cout<<"1";
	 }
	 else
	 {
	 	cout<<"0";
	 }
	 
	return 0;
} 
