#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,e;
	cin>>a>>b>>c>>e;

	if(a==c)
	{
		cout<<"1";
		if(b[0]==e[0] and b[1]==e[1])
		{	
			cout<<"1";
			char b1=b[2],e1=e[2];
			if((b1<='C'and e1<='C') or(b1>'C' and e1>'C'))
			{
				cout<<"1";
				if(abs(b1-e1)==1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else
			{
				cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	
	fclose(stdin);	
	fclose(stdout);	

	return 0;
}
