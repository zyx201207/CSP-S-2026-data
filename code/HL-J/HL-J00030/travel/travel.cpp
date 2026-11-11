#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
bool same(char a,char b)
{
	if(a>='A' && a<='C' && b>='A' && b<='C') return 1;
	else  if(a>='D' && a<='E' && b>='D' && b<='E') return 1;
	else return 0;
} 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		for(int i=0;i<s1.size();i++)
	    {
		    if(i<2)
		    {
			    a+=s1[i];
			    b+=s2[i];
		    }
		    else 
		    {
			    if(a==b)
				{
					cout<<1;
					if(same(s1[i],s2[i]))
					{
						cout<<1;
						if(abs((s1[i]-'A')-(s2[i]-'A'))==1)
			            {
				            if(s1[i]=='C' && s2[i]=='D')      cout<<0;
				            else if(s1[i]=='D' && s2[i]=='C') cout<<0;
				            else cout<<1;
			            } 
			            else cout<<0;
			        }
			        else cout<<"00";
			        
				} 
			    else cout<<"000";
		    }
	    }
	} 
	else cout<<"0000";
	return 0;
}
