#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long f1,f2,f3,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		f1=1;
		cout<<1;
		f++;
		if(f1==1&&b[0]==d[0]&&b[1]==d[1])
		{
			f2=1;
			cout<<1;
			f++;
			if(f2==1&&b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')
			{
				f3=1;
				cout<<1;
				f++;
				if(f3==1&&((b[2]-1==d[2]||b[2]+1==d[2])&&b[2]<='C'&&d[2]<='C')||((b[2]-2==d[2]||b[2]+2==d[2])&&b[2]>'C'&&d[2]>'C'))
				{
					cout<<1;
					f++;
				}
			}
		}
	}
	for(int i=1;i<=4-f;i++)
	cout<<0;
	
	return 0;
} 
