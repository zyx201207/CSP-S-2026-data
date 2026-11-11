#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a=0,c[100000],man=0,ace=0,d=0,i=1;
	cin>>a;
	string b,x;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i]>>x[i];
		
			ace+=c[i];
	 }
	 d=a;
	 	while(d-i>=1){
		 if(x[i]!=x[d]){
	 	     if(c[i]<c[d]){
			  man+=c[i];
			  c[d]-=c[i];
			  i++;			  
			  }
		 else {
		 	man+=c[d];
		 	c[i]-=c[d];
			  d--;
		 }
		 }
		 else if(c[i]<c[d]){
			  c[d]-=c[i];
			  i++;
			  }		 
		 else {
		 	c[i]-=c[d];
			  d--;
	  }
}
	  cout<<man;
	return 0;
 } 
