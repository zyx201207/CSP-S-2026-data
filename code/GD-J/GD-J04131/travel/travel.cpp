#include<bits/stdc++.h>
using namespace std;
string c,r;
char cc,rr;
int cs,rs,l,q;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
     cin>>c>>cs>>cc>>r>>rs>>rr;
     if(c==r)cout<<1;
	 else 
	 {
	  cout<<"0000";	
	  return 0;
	 }
	 if(cs==rs)cout<<1;
	 else 
	 {
	 	cout<<"000";
	 	return 0;
	 }
	 if(cc>='D'&&cc<='F'&&rr>='D'&&rr<='F'||cc>='A'&&cc<='C'&&rr>='A'&&rr<='C')
	{
	 cout<<1;
	 l=1;	
    }
	 else 
	 {
	  cout<<"00";
	  return 0;	
	 }
	  if(cs==rs&&cc==rr+1||cs==rs&&rr==cc+1)
     {
      cout<<1;	
	 }
	 else cout<<0;
    
	
return 0;
}
