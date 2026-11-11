#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
  string a,b,c,d;
  cin>>a>>b>>c>>d;
  int x=0;
  x=(a[0]-'0')*10+(a[1]-'0');
  int y=(c[0]-'0')*10+(c[1]-'0');
  if(x==y) cout<<"1";
  else {
	  cout<<"0000";
	  return 0;}
  int x1=(b[0]-'0')*10+(b[1]-'0');
  int y1=(d[0]-'0')*10+(d[1]-'0');
 
  if(x1==y1) 
  {
	  cout<<"1";

  }
  else 
  {
	  cout<<"000";
	  return 0;}
  int p=b[2]-'A'+1;
  int q=d[2]-'A'+1;
  //cout<<"*"<<p<<q;
  int cnt=0;
  if(p>=1&&p<=3&&q>=1&&q<=3)
  {
	  cout<<"1";cnt++;
	  if(abs(p-q)==1) cout<<"1";
	  else cout<<"0";
  }
  if(p>=4&&p<=6&&q>=4&&q<=6)
  {
	  cnt++;
	  cout<<"1";cnt++;
	  if(abs(p-q)==2) cout<<"1";
	  else cout<<"0";
  }
  if(cnt==0) cout<<"00";
}
