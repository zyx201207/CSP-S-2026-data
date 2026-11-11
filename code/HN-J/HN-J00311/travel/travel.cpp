#include<bits/stdc++.h>
using namespace std;
string box1,chair1,box2,chair2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>box1>>chair1>>box2>>chair2;
	if(box1==box2){
		cout<<1;
		if(chair1[0]+chair1[1]==chair2[0]+chair2[1]){
			cout<<1;
			if((chair1[2]<='B'&&chair2[2]<='C')||(chair1[2]>='D'&&chair2[2]>='D')){
				cout<<1;
				if(chair1[2]+1==chair2[2]||chair2[2]+1==chair1[2])
					cout<<1;
					else{
						cout<<"0";
						return 0;
					}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	

