#include<bits/stdc++.h>
using namespace std;
string a,b,m,n;
int k1,k2,k3,k4;
int main()
{   
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>m>>b>>n;




if(a==b)
{
	k1=1;
	
	if(m[0]==n[0]&&m[1]==n[1])
	{
	 k2=1;
     if(m[2]>='A'&&m[2]<='C'&&n[2]>='A'&&n[2]<='C'||m[2]>='D'&&m[2]<='F'&&n[2]>='D'&&n[2]<='F')
     {
     	k3=1;
     	if(m[2]-1==n[2]||n[2]-1==m[2])
		 {
		 	k4=1;
		} 
		  
	 }
	 
    }
   
}

cout<<k1<<k2<<k3<<k4;
    fclose(stdin);
	fclose(stdout);
	return 0;
}
