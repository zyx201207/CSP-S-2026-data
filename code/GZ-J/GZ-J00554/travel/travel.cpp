//GZ-J00554 韦腾宇 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
char c1[11],c2[11];
char s1[11],s2[11];
bool d[4]={false};
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;

    if(c1[0]==c2[0]&&c1[1]==c2[1])
    {
    	d[0]=true;
    	
    	if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
    	d[1]=true;
    	
    	        if(s1[2]=='C'&&s2[2]=='D')
				{
					d[2]=false;
				}
				else{
				
				
					d[2]=true;
						if(s1[2]-s2[2]==-1||s1[2]-s2[2]==1)
				      {
					    
						d[3]=true;
				}
				}   
    	
        }
}

    for(int i=0;i<=3;i++)
    {
    	if(d[i]==true)
    	{
    		cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
} 
