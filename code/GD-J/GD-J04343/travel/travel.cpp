#include<iostream> 
#include<string>
#include<cstdio>
using namespace std;
string Rc,Rs,Xc,Xs;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>Rc>>Rs>>Xc>>Xs; 
if(Rc==Xc)
{
cout<<1;
       if(Xs[1]==Rs[1]&&Xs[0]==Rs[0])
        {
		cout<<1;
		if((('A'<=Rs[2]&&Rs[2]<='C')&&('A'<=Xs[2]&&Xs[2]<='C'))||(('D'<=Rs[2]&&Rs[2]<='F')&&('D'<=Rs[2]&&Rs[2]<='F')))
         {
		 cout<<1;
		 if((Rs[2]=='D'&&Xs[2]=='C')||(Rs[2]=='C'&&Xs[2]=='D'))
		 cout<<0;
		 else
		 if((Rs[2]-Xs[2]==1)||(Rs[2]-Xs[2]==-1))
		 cout<<1;
		 else
		 cout<<0;
		 }
		  
		  
		  
		  else
		cout<<0<<0;
		}
else
cout<<0<<0<<0;


}
else
cout<<0<<0<<0<<0;
	
	
	
return 0;
}
