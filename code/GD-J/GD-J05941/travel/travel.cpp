#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,is1,is2;
	char s1[3],s2[3];
	cin>>c1>>s1>>c2>>s2;
	s1[2]=is1;
	s2[2]=is2;
	if(c1==c2)
	{
	 	cout<<1;
	 	if(s1[1]==s2[1])
	 	{
	 		cout<<1;
	 		if(is1>=65&&is2>=65)
	 		{
	 			if(is1+1==is2||is1==is2+1)
				 	cout<<1;
				else
					cout<<0;	
			}
			else
				cout<<0;
		}
	}
	else
	{
 	for(int i=0;i<4;i++)
		cout<<0;	
	}
	
	return 0;
}



