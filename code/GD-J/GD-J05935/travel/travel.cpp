#include<bits/stdc++.h>
using namespace std;
int n,m,n1,m1;
char s1[3],s2[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=0;i<3;i++)
		cin>>s1[i];
	n1=(s1[0]-'0')*10+(s1[1]-'0');
	cin>>m;
	for(int i=0;i<3;i++)
		cin>>s2[i];
	m1=(s2[0]-'0')*10+(s2[1]-'0');
	if(n==m)
	{
		cout<<1;
		if(n1==m1)
		{
			cout<<1;
			if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))
			{
				cout<<1;
				if((s1[2]+1==s2[2])||(s1[2]-1==s2[2])) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
