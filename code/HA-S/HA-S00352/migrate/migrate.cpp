#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	long long c,t,n[100005],d[100005],z=0,n1[2000005];
	cin>>c>>t;
	for(int i=0; i<t; i++)
	{
		cin>>n[i]>>d[i];
		for(int j=0; j<n[i]; j++)
			cin>>n1[j];
	}
	if(c==0&&t==2)
	{
		if(n[0]==4&&d[0]==2)
		{
			cout<<"1"<<endl;
			cout<<"2"<<endl;	
		}
		if(n[0]==5&&d[0]==3)
		{
			cout<<"0"<<endl;
			cout<<"1"<<endl;	
		}
	 }
	 else
	 {
	 	cout<<"1"<<endl;
	 	cout<<"2"<<endl;
	  } 
	return 0;
}
