#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		for(int i=1;i<=18;i++){
			if(s1==s2){
				for(int j=1;j<=26;j++){
					if(s1==s2){
						if(s2=s1+1||s2=s1-1)
						cout<<"1111";
						else cout<<"1110";
					}				
				}
				else cout<<"1100";
			}
			else cout<<"1000";
		}
		else cout<<"0000";
	}
	return 0;
}
