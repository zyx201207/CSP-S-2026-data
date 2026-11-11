#include<bits/stdc++.h>
using namespace std;
int main(){ 
   freopen("travel.in","w",stdin);
   freopen("travel.out","r",stdout);
   int n;
   cin>>n;
   string x;
   cin>>x;
   int m;
   cin>>m;
   string y;
   cin>>y;
   int sum=0,sum1=0,sum2=0;
   char a[30]={'A','B','C','D','E'};
   if(n==m){
	    cout<<1;  
   }else{
	   cout<<0<<0<<0<<0;   
	   return 0;
   }
   if(x[0]==y[0] && x[1]==y[1]){
	      cout<<1;
	}else{
		cout<<0<<0<<0;	
		return 0;
    }
    for(int i=0;i<5;i++){
		if(a[i]==x[2]){
			if(i<=2){
				sum=1;
			}else{
				sum=2;
			}
		}
		if(a[i]==y[2]){
			if(i<=2){
				sum1=1;
			}else{
				sum1=2;
			}
		}
	}
	if(sum==sum1){
		cout<<1;
	}
	else{
		cout<<0;
	}
		if(sum==1){
		    if(x[2]=='A'&&y[2]=='B'){
				cout<<1;
				sum2++;
				//return 0;
			}
			if(x[2]=='B'&&y[2]=='C'){
				cout<<1;
				sum2++;
				//return 0;
			}
			if(x[2]=='B'&&y[2]=='A'){
				cout<<1;
				sum2++;
				//return 0;
			}
			if(x[2]=='C'&&y[2]=='B'){
				cout<<1;
				sum2++;
				//return 0;
			}
	    }
	    if(sum==2){
			if(x[2]=='D'&&y[2]=='F'){
				cout<<1;
				sum2++;
				//return 0;
			}
			if(x[2]=='F'&&y[2]=='D'){
				cout<<1;
				sum2++;
				//return 0;
	        }
	     }
	     if(sum2!=0){
			 return 0;
		 }else{
			 cout<<0;
	     }
   return 0;
}
