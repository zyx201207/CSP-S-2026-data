#include<bits/stdc++.h>
using namespace std;
string c_1,c_2,c_3,c_4;
int p_1,p_2;
int main(){
	freopen(travel,r,stdin);
	freopen(travel,w,stdout);
	cin>>c_1>>c_2>>c_3>>c_4;
	if(c_1==c_3)
	{
		cout<<1;
		if(c_2[0]==c_4[0]&&c_2[1]==c_4[1])
		{
			cout<<1;
			if(((c_2[2]=='A'||c_2[2]=='B'||c_2[2]=='C')&&(c_4[2]=='A'||c_4[2]=='B'||c_4[2]=='C'))||((c_2[2]=='D'||c_2[2]=='F')&&(c_4[2]=='D'||c_4[2]=='F')))
			{
			cout<<1;
				if(c_2[2]+1==c_4[2]||c_2[2]-1==c_4[2])
					{
						cout<<1;
					}
				else{
					cout<<0;
					}
			}
			else{
				cout<<0;
				cout<<0;
				}
			}
		else{
		cout<<0;
		cout<<0;
		cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}

	return 0;
} 
