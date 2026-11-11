#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   int a1,a2,b1,b2,c1,c2;
   char e1,e2;
   cin>>a1>>b1>>c1>>e1;
   cin>>a2>>b2>>c2>>e2;
   if(a1==a2||b1==b2){
	    cout<<"1";
	    if(c1==c2){
			 cout<<"1";
			 if(e1>'C'||e2<'D') cout<<"00";
			 else{
				 if(e1<'D'||e2<'D'){
					  cout<<"1";
					  if(e1+1==e2&&e1-1==e2) cout<<"1";
					  else cout<<"0";
				  }
				 if(e1>'C'||e2>'C'){
					  cout<<"1";
					  if(e1+1==e2&&e1-1==e2) cout<<"1";
					  else cout<<"0";
				  }
			 }
			 if(e1<'D'||e2>'C') cout<<"00";
			 else{
				 if(e1<'D'||e2<'D'){
					  cout<<"1";
					  if(e1+1==e2&&e1-1==e2) cout<<"1";
					  else cout<<"0";
				  }
				 if(e1>'C'||e2>'C'){
					  cout<<"1";
					  if(e1+1==e2&&e1-1==e2) cout<<"1";
					  else cout<<"0";
				  }
			 }
		 }else cout<<"000";
   }else cout<<"0000";
   return 0;
}
