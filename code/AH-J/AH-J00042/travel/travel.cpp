#include<bits/stdc++.h>
using namespace std;
int c1,c2,ans;
string s1,s2;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin>>c1>>s1>>c2>>s2;
if(c1==c2){cout<<1;
	ans=1;
}
if(c1!=c2){
	cout<<"0000";
	return 0;
}
if(s1[0]==s2[0]&&s1[1]==s2[1]){
cout<<1;
ans=1;
if(s1[2]>='A'&&s1[2]<='C')
  {
	  if(s2[2]>='A'&&s2[2]<='C')
	  {
		   cout<<1;
		  if(s1[2]!='B'&&s2[2]!='B')
		  { 
			  ans=0;
		  }
		  if(s1[2]=='B'||s2[2]=='B')
		  { 
			  ans=1;
		  }
	  }
	  if(s2[2]=='D'||s2[2]=='F')
	  {
		  cout<<0;
		  ans=0;
	  }
  }
if(s1[2]=='D'||s1[2]=='F')
  {
	  if(s1[2]>='A'&&s1[2]<='C')
	  {
		  cout<<0;
		  ans=0;
	  }
	  if(s1[2]=='D'||s1[2]=='F')
	  {
		  cout<<1;
		  ans=1;
	  }
  }
}
if(s1[0]!=s2[0]||s1[1]!=s2[1]){
cout<<"00";
ans=0;
}
if(ans==0){
	cout<<0;
	return 0;
}
if(ans==1){
	cout<<1;
	return 0;
}
fclose(stdin);
fclose(stdout);
return 0;
}
