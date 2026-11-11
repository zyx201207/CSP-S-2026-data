#include<bits/stdc++.h>
using namespace std;
bool tongyice(string a,string b)
{
	if(a=="A"){
		if(b=="B" || b=="C"){
			return true;
		}
	}
	if(a=="B" ){
		if(b=="A" || b=="C"){
			return true;
		}
	}
	if(a=="C"){
		if(b=="B" || b=="A"){
			return true;
		}
	}
	if(a=="E"){
		if(b=="F"){
			return true;
		}
	}
	if(a=="F"){
		if(b=="E"){
			return true;
		}
	}
}
bool great(string x,string y)
{
	if(x=="A" && y=="B"){
		return true;
	}
	if(x=="B" && y=="A"){
		return true;
	}
	if(x=="C" && y=="B"){
		return true;
	}
	if(x=="B" && y=="C"){
		return true;
	}
	if(x=="E" && y=="F"){
		return true;
	}
	if(x=="F" && y=="E"){
		return true;
	}
}
string x,z;
string y,w;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin>>x>>y>>z>>w;
	string a,b;
	a=y[2],b=w[2];
	if(x==z){
		cout<<1;
		if(y[0]==w[0] && y[1]==w[1]){
	    	cout<<1;
	    	if(a=="E" && b=="F"){
	    		cout<"11";
			}
			if(a=="F" && b=="E"){
	    		cout<"11";
			}
			else{
				cout<<"00";
			}
        }
        else{
        	cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}

