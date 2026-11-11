#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	bool flag,flag2,bian;
	cin >> r1 >> r2 >> x1 >> x2;
	if(r1==x1)
	{
		cout << '1';
		string rh,xh;
	    for(int i=0;i<2;i++)
	    {
		rh+=r2[i];
		xh+=x2[i];
	    }
//	cout << rh << xh;
        if(rh==xh)
        {
        	cout << '1';
        	flag=true;
	    }
	    else
	    {
	    	cout << '0';
	    	flag=false;
	    }
	    if(flag==true&&(r2[2]=='A'||r2[2]=='B'||r2[2]=='C')&&(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'))
	    {
	    	cout << '1';
	    	flag2=true;
	    	bian=1;//1Îª×ó£¬0ÎªÓÒ 
	    	
		}
		else if(flag==true&&(r2[2]=='D'||r2[2]=='F')&&(x2[2]=='D'||x2[2]=='F'))
		{
			cout << '1';
			flag2=true;
			bian=0;
		}
		else
		{
			cout << '0';
			flag2=false;
		}
		if(!flag2) cout << '0';
		else if(flag&&bian==0)
		{
			cout << '1';
		}
		else if(flag&&bian==1&&(r2[2]=='B'||x2[2]=='B'))
		{
			cout << '1';
		}
		else cout << '0';
	}
	else cout << "0000";
	return 0;
}
