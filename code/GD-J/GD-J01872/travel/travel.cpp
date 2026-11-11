#include<bits/stdc++.h>
using namespace std;
string a,b;
char c[10],d[10];
int e[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a;
	for(int i=1;i<=3;i++){
		cin>>c[i];
	} 
	cin>>b;
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	if(a==b){
		e[1]=1;
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=1;i<=1;i++){
		if(c[i]==d[i]&&c[i+1]==d[i+1]){
			e[2]=1;
		}else{
			cout<<"1000";
			return 0;
		}
	}
	for(int i=3;i<=3;i++){
		if(c[i]=='A'){
		   if(d[i]=='B'){
			 e[3]=1,e[4]=1;
		   }
		   if(d[i]=='C'){
			 e[3]=1,e[4]=0;
		   }
		   if(d[i]=='D'||d[i]=='F'){
			 e[3]=0,e[4]=0;
		  }
	    }
	    if(c[i]=='B'){
	       if(d[i]=='A'){
			e[3]=1,e[4]=1;
		   }
		   if(d[i]=='C'){
			e[3]=1,e[4]=1;
		   }
		   if(d[i]=='D'||d[i]=='F'){
			e[3]=0,e[4]=0;
		   }
		}
	    if(c[i]=='C'){
		   if(d[i]=='A'){
			e[3]=1,e[4]=0;
		   }
		   if(d[i]=='B'){
			e[3]=1,e[4]=1;
		   }
		   if(d[i]=='D'||d[i]=='F'){
			e[3]=0,e[4]=0;
		   }
		}
	    if(c[i]=='D'){
		   if(d[i]=='A'){
			e[3]=0,e[4]=0;
		   }
		   if(d[i]=='B'){
			e[3]=0,e[4]=0;
		   }
		   if(d[i]=='C'){
		  	e[3]=0,e[4]=0;
		   }
		   if(d[i]=='F'){
		  	e[3]=1,e[4]=1;
		   }
		}
	    if(c[i]=='F'){
			if(d[i]=='A' || d[i]=='B' || d[i]=='C'){
				e[3]=0,e[4]=0;
			}
			if(d[i]=='D'){
				e[3]=1,e[4]=1;
			}
	    }
	}
	for(int i=1;i<=4;i++){
		cout<<e[i];
	}
	return 0;
}
