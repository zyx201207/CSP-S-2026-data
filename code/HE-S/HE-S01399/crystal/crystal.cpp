#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==1)
	{
		cout<<" ";
		return 0;
	}
	else if(n==2)
	{
		if(m==1)
		{
			if(a[1]-a[0]==1||a[1]==a[0])
			{
				cout<<"2";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;		
			}		
		}
		else if(m==2)
		{
			if(a[1]-a[0]==2||a[1]==a[0])
			{
				cout<<"2";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;
			}		
		}
		else if(m==3)
		{
			if(a[1]-a[0]==3||a[1]==a[0]||a[1]-a[0]==1)
			{
				cout<<"2";
				return 0;		
			}
			
			else
			{
				cout<<" ";
				return 0;
			}		
		}
		else if(m==4)
		{
			if(a[1]-a[0]==4||a[1]==a[0]||a[1]-a[0]==2)
			{
				cout<<"2";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;
			}		
		}
		else if(m==5)
		{
			if(a[1]-a[0]==5||a[1]==a[0]||a[1]-a[0]==3||a[1]-a[0]==1)
			{
				cout<<"2";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;
			}		
		}
		else if(m==6)
		{
			if(a[1]-a[0]==6||a[1]==a[0]||a[1]-a[0]==4||a[1]-a[0]==2)
			{
				cout<<"2";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;
			}		
		}
		else if(m==7)
		{
			if(a[1]-a[0]==7||a[1]==a[0]||a[1]-a[0]==5||a[1]-a[0]==3||a[1]-a[0]==1)
			{
				cout<<"2";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;
			}		
		}
		else if(m==8)
		{
			if(a[1]-a[0]==8||a[1]==a[0]||a[1]-a[0]==6||a[1]-a[0]==4||a[1]-a[0]==2)
			{
				cout<<"2";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;
			}		
		}
		else if(m==9)
		{
			if(a[1]-a[0]==9||a[1]==a[0]||a[1]-a[0]==7||a[1]-a[0]==5||a[1]-a[0]==3||a[1]-a[0]==1)
			{
				cout<<"2";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;
			}		
		}
		else if(m==10)
		{
			if(a[1]-a[0]==10||a[1]==a[0]||a[1]-a[0]==8||a[1]-a[0]==6||a[1]-a[0]==4||a[1]-a[0]==2)
			{
				cout<<"2";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;
			}		
		}			
	}
	else if(n==3)
	{
		if(a[0]==a[1]&&a[1]==a[2])
		{
			cout<<"3";
			return 0;
		}
		else if(m==1)
		{
			if(a[1]==a[2]&&a[1]-a[0]==1)
			{
				cout<<"3";	
				return 0;	
			}
			else
			{
				cout<<" ";
				return 0;		
			}		
		}
		else if(m==2)
		{
			if(a[0]==a[1]&&a[2]-a[1]==1)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]==a[2]&&a[1]-a[0]==2)
			{
				cout<<"3";
				return 0;		
			}	
			else
			{
				cout<<"2";
				return 0;
			}
		}
		else if(m==3)
		{
			if(a[1]==a[2]&&a[1]-a[0]==3)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[2]-a[1]==1&&a[1]-a[0]==1)
			{
				cout<<"3";
				return 0;		
			}
			else
			{
				cout<<"2";
				return 0;		
			}		
		}
		else if(m==4)
		{
			if(a[1]==a[2]&&a[1]-a[0]==4)	
			{
				cout<<"3";
				return 0;	
			}	
			else if(a[0]==a[1]&&a[2]-a[1]==2)
			{
				cout<<"3";
				return 0;
			}
			else if(a[1]-a[0]==2&&a[2]-a[1]==1)
			{
				cout<<"3";
				return 0;
			}
			else
			{
				cout<<"2";
				return 0;
			}
		}
		else if(m==5)
		{
			if(a[1]==a[2]&&a[1]-a[0]==5)
			{
				cout<<"3";
				return 0;
			}
			else if(a[1]-a[0]==3&&a[2]-a[1]==1)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==1&&a[2]-a[1]==2)
			{
				cout<<"3";
				return 0;		
			}	
			else
			{
				cout<<"2";
				return 0;	
			}	
		}
		else if(m==6)
		{
			if(a[1]==a[2]&&a[1]-a[0]==6)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[0]==a[1]&&a[2]-a[1]==3)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==4&&a[2]-a[1]==1)
			{
				cout<"3";
				return 0;	
			}
			else if(a[1]-a[0]==2&&a[2]-a[1]==2)
			{
				cout<<"3";
				return 0;	
			}	
		}
		else if(m==7)
		{
			if(a[1]==a[2]&&a[1]-a[0]==7)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==5&&a[2]-a[1]==1)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==3&&a[2]-a[1]==2)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==1&&a[2]-a[1]==3)
			{
				cout<<"3";
				return 0;		
			}
			else
			{
				cout<<"2";
				return 0;		
			}		
		}
		else if(m==8)
		{
			if(a[1]==a[2]&&a[1]-a[0]==8)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==6&&a[2]-a[1]==1)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==4&&a[2]-a[1]==2)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==2&&a[2]-a[1]==3)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[0]==a[1]&&a[2]-a[1]==4)
			{
				cout<<"3";
				return 0;
			}
			else
			{
				cout<<"2";
				return 0;		
			}			
		}
		else if(m==9)
		{
			if(a[1]==a[2]&&a[1]-a[0]==9)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==7&&a[2]-a[1]==1)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==5&&a[2]-a[1]==2)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==3&&a[2]-a[1]==3)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==1&&a[2]-a[1]==4)
			{
				cout<<"3";
				return 0;
			}
			else
			{
				cout<<"2";
				return 0;		
			}		
		}
		else if(m==10)
		{
			if(a[1]==a[2]&&a[1]-a[0]==10)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==8&&a[2]-a[1]==1)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==6&&a[2]-a[1]==2)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==4&&a[2]-a[1]==3)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[1]-a[0]==2&&a[2]-a[1]==3)
			{
				cout<<"3";
				return 0;		
			}
			else if(a[0]==a[1]&&a[2]-a[1]==5)
			{
				cout<<"3";
				return 0;		
			}
			else
			{
				cout<<"2";
				return 0;		
			}		
		}		
	}
	else if(n==4)
	{
		if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])
		{
			cout<<"4";
			return 0;
		}
		else if(m==1)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[1]-a[0]==1)
			{
				cout<<"4";
				return 0;		
			}		
			else
			{
				cout<<" ";
				return 0;
			}
		}
		else if(m==2)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[1]-a[0]==2)
			{
				cout<<"4";
				return 0;
			}
			else if(a[0]==a[1]&&a[2]==a[3]&&a[2]-a[1]==1)
			{
				cout<<"4";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;
			}
		}
		else if(m==3)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[1]-a[0]==3)
			{
				cout<<"4";
				return 0;
			}		
			else if(a[1]-a[0]==1&&a[2]==a[3]&&a[2]-a[1]==1)
			{
				cout<<"4";
				return 0;
			}
			else
			{
				cout<<" ";
				return 0;
			}			
		}
		else if(m==4)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[1]-a[0]==4)
			{
				cout<<"4";
				return 0;
			}
			else if(a[0]==a[1]&&a[2]==a[3]&&a[2]-a[1]==2)
			{
				cout<<"4";
				return 0;		
			}
			else if(a[1]-a[0]==2&&a[2]==a[3]&&a[2]-a[1]==1)
			{
				cout<<"4";
				return 0;		
			}		
			else
			{
				cout<<" ";
				return 0;
			}		
		}
		else if(m==5)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[1]-a[0]==5)
			{
				cout<<"4";
				return 0;
			}		
			else if(a[1]-a[0]==3&&a[2]==a[3]&&a[2]-a[1]==1)
			{
				cout<<"4";
				return 0;
			}
			else if(a[1]-a[0]==1&&a[2]==a[3]&&a[2]-a[1]==2)
			{
				cout<<"4";
				return 0;
			}
			else
			{
				cout<<" ";
				return 0;
			}				
		}
		else if(m==6)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[1]-a[0]==6)
			{
				cout<<"4";
				return 0;
			}
			else if(a[0]==a[1]&&a[2]==a[3]&&a[2]-a[1]==3)
			{
				cout<<"4";
				return 0;		
			}
			else if(a[1]-a[0]==4&&a[2]==a[3]&&a[2]-a[1]==1)
			{
				cout<<"4";
				return 0;		
			}
			else if(a[1]-a[0]==2&&a[2]==a[3]&&a[2]-a[1]==2)
			{
				cout<<"4";
				return 0;		
			}		
			else
			{
				cout<<" ";
				return 0;
			}		
		}
		else if(m==7)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[1]-a[0]==7)
			{
				cout<<"4";
				return 0;
			}
			else if(a[1]-a[0]==5&&a[2]==a[3]&&a[2]-a[1]==1)
			{
				cout<<"4";
				return 0;		
			}		
			else if(a[1]-a[0]==3&&a[2]==a[3]&&a[2]-a[1]==2)
			{
				cout<<"4";
				return 0;
			}
			else if(a[1]-a[0]==1&&a[2]==a[3]&&a[2]-a[1]==3)
			{
				cout<<"4";
				return 0;
			}
			else
			{
				cout<<" ";
				return 0;
			}			
		}
		else if(m==8)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[1]-a[0]==8)
			{
				cout<<"4";
				return 0;
			}
			else if(a[0]==a[1]&&a[2]==a[3]&&a[2]-a[1]==4)
			{
				cout<<"4";
				return 0;		
			}		
			else if(a[1]-a[0]==6&&a[2]==a[3]&&a[2]-a[1]==1)
			{
				cout<<"4";
				return 0;		
			}
			else if(a[1]-a[0]==4&&a[2]==a[3]&&a[2]-a[1]==2)
			{
				cout<<"4";
				return 0;		
			}
			else if(a[1]-a[0]==2&&a[2]==a[3]&&a[2]-a[1]==3)
			{
				cout<<"4";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;
			}		
		}
		else if(m==9)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[1]-a[0]==9)
			{
				cout<<"4";
				return 0;
			}
			else if(a[1]-a[0]==7&&a[2]==a[3]&&a[2]-a[1]==1)
			{
				cout<<"4";
				return 0;		
			}
			else if(a[1]-a[0]==5&&a[2]==a[3]&&a[2]-a[1]==2)
			{
				cout<<"4";
				return 0;		
			}		
			else if(a[1]-a[0]==3&&a[2]==a[3]&&a[2]-a[1]==3)
			{
				cout<<"4";
				return 0;
			}
			else if(a[1]-a[0]==1&&a[2]==a[3]&&a[2]-a[1]==4)
			{
				cout<<"4";
				return 0;
			}
			else
			{
				cout<<" ";
				return 0;
			}			
		}
		else if(m==10)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[1]-a[0]==10)
			{
				cout<<"4";
				return 0;
			}
			else if(a[0]==a[1]&&a[2]==a[3]&&a[2]-a[1]==5)
			{
				cout<<"4";
				return 0;		
			}		
			else if(a[1]-a[0]==8&&a[2]==a[3]&&a[2]-a[1]==1)
			{
				cout<<"4";
				return 0;		
			}
			else if(a[1]-a[0]==6&&a[2]==a[3]&&a[2]-a[1]==2)
			{
				cout<<"4";
				return 0;		
			}
			else if(a[1]-a[0]==4&&a[2]==a[3]&&a[2]-a[1]==3)
			{
				cout<<"4";
				return 0;		
			}
			else if(a[1]-a[0]==2&&a[2]==a[3]&&a[2]-a[1]==4)
			{
				cout<<"4";
				return 0;		
			}
			else
			{
				cout<<" ";
				return 0;
			}		
		}		
	}
	else if(n==5)
	{
		if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4])
		{
			cout<<"5";
			return 0;
		}
		else if(m==1)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[1]-a[0]==1)
			{
				cout<<"5";
				return 0;		
			}		
		}
		else if(m==2)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[1]-a[0]==2)
			{
				cout<<"5";
				return 0;		
			}
			else if(a[0]==a[1]&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==1)
			{
				cout<<"5";
				return 0;				
			}				
		}
		else if(m==3)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[1]-a[0]==3)
			{
				cout<<"5";
				return 0;		
			}
			else if(a[1]-a[0]==1&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==1)
			{
				cout<<"5";
				return 0;			
			}			
		}
		else if(m==4)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[1]-a[0]==4)
			{
				cout<<"5";
				return 0;		
			}
			else if(a[1]-a[0]==2&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==1)
			{
				cout<<"5";
				return 0;			
			}			
		}
		else if(m==5)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[1]-a[0]==5)
			{
				cout<<"5";
				return 0;		
			}
			else if(a[1]-a[0]==3&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==1)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==1&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==2)
			{
				cout<<"5";
				return 0;			
			}			
		}
		else if(m==6)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[1]-a[0]==6)
			{
				cout<<"5";
				return 0;		
			}
			else if(a[1]-a[0]==4&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==1)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==2&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==2)
			{
				cout<<"5";
				return 0;			
			}			
		}
		else if(m==7)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[1]-a[0]==7)
			{
				cout<<"5";
				return 0;		
			}
			else if(a[1]-a[0]==5&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==1)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==3&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==2)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==1&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==3)
			{
				cout<<"5";
				return 0;			
			}			
		}
		else if(m==8)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[1]-a[0]==8)
			{
				cout<<"5";
				return 0;		
			}
			else if(a[1]-a[0]==6&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==1)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==4&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==2)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==2&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==3)
			{
				cout<<"5";
				return 0;			
			}			
		}
		else if(m==9)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[1]-a[0]==9)
			{
				cout<<"5";
				return 0;		
			}
			else if(a[1]-a[0]==7&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==1)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==5&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==2)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==3&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==3)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==1&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==4)
			{
				cout<<"5";
				return 0;			
			}			
		}
		else if(m==10)
		{
			if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[1]-a[0]==10)
			{
				cout<<"5";
				return 0;		
			}
			else if(a[1]-a[0]==8&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==1)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==6&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==2)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==4&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==3)
			{
				cout<<"5";
				return 0;			
			}
			else if(a[1]-a[0]==2&&a[2]==a[3]&&a[3]==a[4]&&a[2]-a[1]==4)
			{
				cout<<"5";
				return 0;			
			}			
		}		
	}
	cout<<"3";
	return 0;
}
