#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	int n=c2[2]-'A',m=c4[2]-'A';
	if(c1[0]==c3[0] && c1[1]==c3[1]) 
	{
		cout<<1;
		if(c2[1]==c4[1]){
		cout<<1;
			if((n<=2 && m<=2) || (n>=3 && m>=3))
			{
				cout<<1;
				if(abs(n-m)==1)
					cout<<1;
				else
					cout<<0;
			}
			else
			cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
