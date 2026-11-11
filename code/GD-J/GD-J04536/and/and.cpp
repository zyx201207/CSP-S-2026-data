#include <bits/stdc++.h>
using namespace std;
long long x,y,z,ma;
long long ar[100100],num[100100];
int dp(long long a){
int w=y;
//cout<<a<<"-------------";
	long long o=ar[a],p=0,q=0;z=1;
	for(int i=1;i<=y;i++){
		//cout<<a<<' '<<i<<' '<<y<<endl;
		if(i>=w){
			//cout<<i<<' '<<w-1<<' ';
			//cout<<i<<' ';
			if(z<=x){
		    	//cout<<"-"<<z<<'-';
		    	 q=max(o,q);
			     cout<<q<<endl;
		     	o=ar[a];
			     y=1;
			p=0;
	    	}
		}
		//cout<<a<<' '<<i<<' '<<y<<endl;
		
		if(z+p>=x){//cout<<z+p<<' '<<x;
		break;}
		   
			  
		
	//	cout<<i<<'+';
		//cout<<o<<' '<<ar[i+z+p]<<endl;
	     o=o and ar[i+z+p];
	     
	        if(i=2)z=w;
	    	else z+=w-1;
	    	
	    	p++;
	    //	cout<<a<<' '<<i<<' '<<y<<endl;
	    //	cout<<"=="<<p<<'-';
	}
	return q;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		cin>>ar[i];
	}
	z=1;
	for(long long a=1;a<x;a++){
		long long answer=dp(a);
	//	cout<<"  =="<<answer;
		ma=max(ma,answer); 
		
	}
	cout<<ma;
	return 0;
}
