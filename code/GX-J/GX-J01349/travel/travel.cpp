#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b[2]=='F')b[2]='E';
	if(d[2]=='F')d[2]='E';
	bool e=0,f=0,g=0,h=0;
	e=0;
	if(a==c){
		e=1;
		}else{
			cout<<"0000";
			return 0;
			}
     if(b[0]==d[0]&&b[1]==d[1])f=1;
    if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E'))
    if(f==1)
    g=1;
    int r1=int(b[0]-'0')*10+int(b[1]-'0');
    int r2=int(d[0]-'0')*10+int(d[1]-'0');
  int r=abs(r1-r2);
  int x=abs(int(b[2]-d[2]));
  if(r+x==1&&g==1)h=1;
    cout<<e<<f<<g<<h;
	return 0;
	}
//miao~miao~miao~
