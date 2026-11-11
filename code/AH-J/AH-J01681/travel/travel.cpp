#include<bits/stdc++.h>
using namespace std;
int x,y;
string x1,y1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>x1>>y>>y1;
	if(x==y) 
	    cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	    
	int m,n;
	m=x1[2]-'A';
	n=y1[2]-'A';  
	if(x1[0]==y1[0]&&x1[1]==y1[1]){
		cout<<"1";
		if((m==0&&n==1)||(m==1&&n==0)||(m==2&&n==1)||(m==1&&n==2)||(m==2&&n==0)||(m==0&&n==2))
		    cout<<"1";
		else{
			if((m==4&&n==3)||(m==3&&n==4))
			    cout<<"1";
			else{
				cout<<"00";
				return 0;
			}   
		}
		if((m-n)==1||(n-m)==1)
		    cout<<"1";
		else
		    cout<<"0";
	}
	else{
		cout<<"000";
		return 0;
	}
	return 0;
}
