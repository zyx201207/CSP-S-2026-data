//GZ-J00193 个人报名 李青云
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool ans1=1,ans2=0,ans3=0,ans4=0;
	for(int i=0;i<2;i++)
    {
        if(c1[i]!=c2[i])
	    {
	       ans1=0;
		   break;
	    }
    }
	if(ans1)
	{
	    for(int i=0;i<2;i++)
	    {
		    if(s1[i]!=s2[i])
		    {
			    break;
			}
			ans2=1;
		}
	}
	if(ans2)
	{
	    if(max(s1[2]-'A',s2[2]-'A')>='D')
	    {
		    if(max(s1[2]-'A',s2[2]-'A')-min(s1[2]-'A',s2[2]-'A')>1)
		    {
			    ans3=0;
			}
			ans3=1;
		}
		else
		{
		    if(max(s1[2]-'A',s2[2]-'A')-min(s1[2]-'A',s2[2]-'A')>2)
		    {
			    ans3=0;
			}
			ans3=1;
		}

	}
	if(ans3)
	{
        if(max(s1[2]-'A',s2[2]-'A')=='D')
	    {
		    ans4=0;
		}
		else
	    {
		    if(max(s1[2]-'A',s2[2]-'A')-min(s1[2]-'A',s2[2]-'A')==1)
	        {
		        ans4=1;
		    }
		}
	}
    cout<<ans1<<ans2<<ans3<<ans4;
   return 0;
}

