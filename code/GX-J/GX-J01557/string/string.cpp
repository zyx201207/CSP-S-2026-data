#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   long long a,b,e=0,f,g=0;
   string d;
   char c;
   cin>>a;
   for(int i=1;i<=a;i++){
	   cin>>b>>c;
	   for(int j=e;j<e+b;j++){
		   d+=c;
		}
		e+=b;
	}
	e=d.size();
	f=sqrt(e)+1;
	for(int i=1;i<f;i++){
		if(d[f+1]!=d[f-1])g++;
	}	
	cout<<g;		   
	return 0;
}	   
