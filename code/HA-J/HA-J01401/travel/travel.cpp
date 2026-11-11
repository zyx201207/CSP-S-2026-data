#include<bits/stdc++.h>
using namespace std;
string ttnoa,ttnob,tsnoa,tsnob;
bool flag;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ttnoa>>tsnoa;
	cin>>ttnob>>tsnob;
	if(ttnoa==ttnob)
		cout<<1;
	else{
		cout<<0;
		flag=1;
	}
	
	
	if(tsnoa[0]==tsnob[0]&&tsnoa[1]==tsnob[1]&&flag==0)
		cout<<1;
	else{
		cout<<0;
		flag=1;
	}
	
	
	if((tsnoa[2]<='C'&&tsnob[2]>='D')||(tsnob[2]<='C'&&tsnoa[2]>='D')||flag==1){
		cout<<0;
		flag=1;
	}
	else
		cout<<1;
	
	
	if(abs(tsnoa[2]-tsnob[2])==1&&flag==0)
		cout<<1;
	else
		cout<<0;
	return 0;
}
