#include<iostream> 
#include<string> 
#include<algorithm>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ra,rb,xa,xb;
	cin>>ra>>rb>>xa>>xb;
	if(ra==xa)
	{
		cout<<1;
		if(rb.substr(0,2)==xb.substr(0,2))
		{
			cout<<1;
			if(rb[2]>='A' && rb[2]<='C' && xb[2]>='A' && xb[2]<='C')
			{
				cout<<1;
				if(abs((int)rb[2]-xb[2])==1)
				{
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(rb[2]>='D' && rb[2]<='F' && xb[2]>='D' && xb[2]<='F')
			{
				cout<<11;
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
