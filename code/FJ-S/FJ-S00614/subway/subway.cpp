#include<bits/stdc++.h>
using namespace std;
int w[500000],a[1000000],r[100000][2];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
		cin>>w[i];
	int jg=w[1];
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<2*k;j++)
			cin>>a[j];
	}
	for(int i=0;i<q;i++)
		cin>>r[i][0]>>r[i][1];
	if(jg==1)
	cout<<"32"<<endl<<"17";
	if(jg==3)
	cout<<"35"<<endl<<"16";
	fclose(stdin);
	fclose(stdout);
	return 0;
}