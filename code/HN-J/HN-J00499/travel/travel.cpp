#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,x,y;
    cin>>a>>b>>x>>y;
    int n,m,g=0,g1=0,g2=0;
    if(b[2]!='D')
      n=b[2]-'A'+1;
    else
      n=5;
    if(y[2]!='D')
	  m=y[2]-'A'+1;
	else
	  m=5;     
    if(a==x){
      cout<<"1";
      g=1;
    }
    else
	  cout<<"0";
	if(b[0]==y[0] && b[1]==y[1] && g==1){
	  cout<<"1";
	  g1=1;
    }
	else
	  cout<<"0";
    if(n>=5 && m>=5 || n<=3 && m<=3 && g==1 && g1==1){
	  cout<<"1";
	  g2=1;
    }
	else
	  cout<<"0";
	if(abs(n-m)==1 && g==1 && g1==1 && g2==1)
	  cout<<"1";
	else
	  cout<<"0";           
	return 0;
}
