#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,x,y;
	cin>>n>>m>>x>>y;
	if(n[0]==x[0]&&n[1]==x[1]){
		if(m[0]==y[0]){		
			if(m[1]==y[1]){
				if((m[2]=='C'&&y[2]=='D')||(m[2]=='D'&&y[2]=='C')){
					cout<<1110;
				}	
				else if(m[2]+0==y[2]+1||m[2]+0==y[2]-1)	{
					cout<<1111;
				}
				else cout<<1110;
			}		
			else cout<<1110;
		}		
		else cout<<1110;
	}
	else cout<<1110;
	
	
	return 0;
}
