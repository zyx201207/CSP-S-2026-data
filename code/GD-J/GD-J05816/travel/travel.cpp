#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cnt=0; 
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1])
	{
		cout<<"1";
		cnt++;
	    if(s2[1]==s1[1])
	    {
		    cout<<"1";    
		    cnt++;
		    if((s2[2]-64<=3 && s1[2]-64<=3)||((s2[2]-64)>3 && (s1[2]-64)>3))
		    {
			    cout<<"1";
			    cnt++;
			    if((s1[2]-64)-(s2[2]-64)==1||(s1[2]-64)-(s2[2]-64)==-1)
			    {
			  	    cout<<"1";
			  	    cnt++;
			    }
			    else
			    {
				    cout<<"0";
				    cnt++;
			    }
	     	}
			
		}
		else
		{
		    cout<<"0";
		    cout<<"0";
		    cout<<"0" ;
		    cnt+=3;
		}
    }
	else
	{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cnt+=4;
		cout<<"0";
    }
    if(cnt!=4){
    	for(int i=0;i<=4-cnt;i++)
    	{
    		cout<<"0";
		}
	}
	return 0; 
}
