#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x1,x2;
	string y1,y2;
	cin>>x1>>y1>>x2>>y2;
	char a=y1[0],b=y1[1],c=y2[0],d=y2[1];
	if(x1==x2){
		if(a==c and b==d){
			if(y1[2]-1==int(y2[2]) || y1[2]+1==int(y2[2])){
				if(y1[2]+1==int('D')||y1[2]-1==int('C')){
					cout<<"1100";
				}
				else cout<<"1111";				
			}
			else{
				cout<<"1110";
			}
		}
		else{
			cout<<"1000";
		}
		}
	else{
		cout<<"0000";
	}
}
