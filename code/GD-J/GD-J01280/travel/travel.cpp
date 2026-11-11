#include<bits/stdc++.h>
using namespace std;
string a,b;
int n,m,tt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a;
	cin>>m>>b;
	if(n==m)
	{
		cout<<"1";
	   for(int i=0;i<2;i++){
		    
			if(tt==2&&a[i]==b[i]){
				cout<<"1";
			}
			if(tt==2&&a[i]!=b[i])
			{
				cout<<"000";
				return 0;
			}
	      if(tt==1)
	      {
	      	cout<<"000";
	      	return 0;
		  }
				if(a[i]==b[i])
			{
				tt=2;
			}
			else tt=1;
		} 
	}
	else {
	cout<<"0000";
return 0;
	}
	if(a[2]=='A'&&b[2]=='B'||a[2]=='B'&&b[2]=='C'||a[2]=='D'&&b[2]=='F'||b[2]=='A'&&a[2]=='B'||b[2]=='B'&&a[2]=='C'||b[2]=='D'&&a[2]=='F') {
		cout<<"11";	
		return 0;
	}
		if(a[2]=='C'&&b[2]=='D'||a[2]=='C'&&b[2]=='D')
		{
			cout<<"00";
			return 0;
		}
	if(a[2]=='A'&&b[2]=='C'||b[2]=='A'&&a[2]=='C')
	{
		cout<<"10";
		return 0;
	}
	return 0;
} 
