#include<bits/stdc++.h>
using namespace std;
string ra,rb,xa,xb;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  cin>>ra>>rb>>xa>>xb;
  int che=1,pai=1;
  for(int i=0;i<3;i++){
  	if(ra[i]==xa[i]){continue;}
  	else {che=0;break;}
  }cout<<che;
  if(che==1){
  	for(int i=0;i<2;i++){
  		if(rb[i]==xb[i])continue;
  		else pai=0;
  	}
  	
  }else pai=0;
  cout<<pai;
  int guo=1;
  int a,b,c;
  a=rb[2]-'A';
  b=xb[2]-'A';
  c=max(a-b,b-a);
  if(pai==1){
  	if(c==2&&a+b!=8&&a+b!=2) guo=0;
  	else if(c>2)guo=0;
  	else if(c==1&&a+b==5)guo=0;
  	else ;
  }else guo=0;
  cout<<guo;
  if(guo==1){
  if(c==2&&a+b!=8){
  	cout<<0;
  	return 0;
  }
  else cout<<1;
  }else cout<<0;
  return 0;
}

