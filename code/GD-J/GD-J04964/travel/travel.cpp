#include<bits/stdc++.h>
using namespace std;
int x1,x2,y1,y2,z1,z2;
string n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>n>>x2>>m;
	y1=n[0]-'0'+n[1]-'0';
	y2=m[0]-'0'+m[1]-'0';
	z1=n[2]-'A';
	z2=m[2]-'A';
	if(x1==x2){
		cout<<1;
		if(y1==y2){
			cout<<1;
		    if((z1==0&&z2==1)||(z2==0&&z1==1)||(z1==2&&z2==1)||(z2==2&&z1==1)||(z1==0&&z2==2)||(z1==2&&z2==0)||(z1==5&&z2==3)||(z1==3&&z2==5)){
		    	cout<<1;
		    	if((z1==0&&z2==1)||(z2==0&&z1==1)||(z1==2&&z2==1)||(z2==2&&z1==1)||(z1==5&&z2==3)||(z1==3&&z2==5)){
		    		cout<<1;
				}			
				else{
					cout<<0;
				}    
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
