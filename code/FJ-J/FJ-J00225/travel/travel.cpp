#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string c1,c2;
int hm1,hm2;
int main()
{
	freopen("travel.in.txt","r",stdin);
	freopen("travel.out.txt","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
		int len1=s1.size();
    	int len2=s2.size();
    	for(int i=0;i<2;i++)
    	{
	    	hm1=hm1*10+s1[i]-'0';
	    	hm2=hm2*10+s2[i]-'0';
	    }
	    if(hm1==hm2)
		{
			cout<<'1';
			if(s1[2]<='C'&&s1[2]>='A')
	        {
	        	if(s2[2]<='C'&&s2[2]>='A')
	        	{
	        		cout<<'1';
	        		if(abs(s1[2]-s2[2])==1)cout<<'1';
	        		else cout<<'0';
	    	    }
	    	    else cout<<"00";
	        }
         	if(s1[2]=='D'||s2[2]=='F'){
    	    	if(s2[2]=='D'||s2[2]=='F')
				{
			    	cout<<'1';
					cout<<'1';
				}
    	    	else cout<<"00";
        	}
        }
        else cout<<"000";
    }   
	else cout<<"0000";
	return 0;
}
