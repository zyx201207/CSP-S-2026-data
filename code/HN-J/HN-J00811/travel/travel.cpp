#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int m[10]={0,0,0,1,1},z;

bool pd(){
	if(m[a2[2]]==0){
		if(abs(a2[2]-b2[2])==1)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	a2[2]-='A';
	b2[2]-='A';
	if(a1==b1){
		cout<<1;
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<1;
			if(m[a2[2]]==m[b2[2]]){
				cout<<1;
				if(pd()==1)
					cout<<1;
				
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
