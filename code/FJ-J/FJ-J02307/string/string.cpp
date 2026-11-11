#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m=0,x,biao,z=0;
	string si[100002];
	int mi[100002]={0};
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		string c;
		int a;
		cin>>a>>c;
		si[i]=c;
		m+=a;
		mi[i]=m;
	}
	int v1,v2,g1,g2; 
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(mi[i]==mi[j])
			{
				v1=mi[i-1];
				v2=mi[i];
				g2=m-mi[j];
				g1=m-mi[j-1];
				z+=max(v1,g1)-min(v2,g2);
				//cout<<min(v2,g2)<< " "<<max(v1,g1)<<"\n"<<v1<<" "<<v2<<" "<<g1<<" "<<g2<<"\n";
			}
		}
	}
	cout<<m/2-z/2;
	return 0;
}
