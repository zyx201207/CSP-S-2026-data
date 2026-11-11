#include<bits/stdc++.h>
using namespace std;
string rcx,rzw,xcx,xzw;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rcx>>rzw>>xcx>>xzw;
	int shur=rzw[2]-'C';
	int shux=xzw[2]-'C';
	int shu=shur-shux;
	if(rcx!=xcx)
	{
		cout<<"0000";
	}else{
		if(rzw[0]==xzw[0] && rzw[1]==xzw[1])
		{
			if(shur>0 && shux>0)
			{
				cout<<"1111";
			}else{
				if(shur<=0 && shux<=0){
					if(shu==1 || shu==-1)
					{
						cout<<"1111";
					}else{
						cout<<"1110";
					}	
				}else{
					cout<<"1100";
				}
			}
		}else{
			cout<<"1000";
		}
	}
	
	return 0;
}
