#include<bits/stdc++.h>
using namespace std;
char r[5],x[5];
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin.getline(r,5);
cin.getline(x,5);
if(r[0]==x[0]&&r[1]==x[1]){
	cout<<"1";
	}
else{
cout<<"0000";
return 0;
}
if(r[2]==x[2]&&r[3]==x[3]){
	cout<<"1";
	}
	else{
		cout<"000";
		return 0;
		}
		if((r[4]=='C'&&x[4]=='D')||(r[4]=='D'&&x[4]=='D')){
			cout<<"00";
			return 0;
			}
			else{
				cout<<1;
				}
				if(r[4]-x[4]==-1||r[4]-x[4]==1){
					cout<<1;
					return 0;
					}
					else
					{
				cout<<"0";		
						return 0;
				}
return 0;
}
