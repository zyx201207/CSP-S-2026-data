#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string train1,train2;
	string seat1,seat2;
	cin>>train1>>seat1>>train2>>seat2;
	if(train1==train2)
	{
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(seat1[0]==seat2[0]&&seat1[1]==seat2[1])
	{
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(seat1[2]=='A'||seat1[2]=='B'||seat1[2]=='C')
	{
		if(seat2[2]=='A'||seat2[2]=='B'||seat2[2]=='C')
		{
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
		if(seat1[2]=='A')
    	{
    		if(seat2[2]=='B')
    		{
    			cout<<"1";
    			return 0;
    		}else{
    			cout<<"0";
    			return 0;
    		}
    	}else if(seat1[2]=='C')
    	{
    		if(seat2[2]=='B')
    		{
    			cout<<"1";
    			return 0;
    		}else{
    			cout<<"0";
    			return 0;
    		}
    	}else{
			cout<<"1";
			return 0;
		}
    }else{
		if(seat2[2]=='D'||seat2[2]=='F')
		{
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
    }
    
}
