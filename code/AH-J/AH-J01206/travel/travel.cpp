#include<bits/stdc++.h>
using namespace std;
string a,b;
int c,d;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  cin>>c>>a;
  cin>>d>>b;
  char m=a[2],n=b[2];
  int x=a[0]*10+a[1],y=b[0]*10+b[1];
  if(c==d)cout<<"1";
  else {
	  cout<<"0000";
	  return 0;
	  }
  if(x==y)cout<<"1";
  else {
	  cout<<"000";
	  return 0;}
  if(((m=='A'||m=='B'||m=='C')&&(n=='A'||n=='B'||n=='C'))||((m=='E'||m=='F')&&(n=='E'||n=='F')))cout<<"1";
  else {
	  cout<<"00";
	  return 0;}
  if(m=='A' && n=='B'||m=='B' && n=='A'||m=='B' && n=='C'||m=='C' && n=='B'||m=='E' && n=='F'||m=='F' && n=='E')cout<<"1";
  else cout<<"0";
  return 0;
}
