#include<bits/stdc++.h>
using namespace std;
int c1,c2,q[10],w[10];
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=0;i<=2;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<=2;i++){
		cin>>s2[i];
	}
	q[1]=s1[0]-'0'+s1[1]-'0';
	q[2]=s1[2]-'A';
	w[1]=s2[0]-'0'+s2[1]-'0';
	w[2]=s2[2]-'A';
	if(c1==c2){
		cout<<"1";
		if(q[1]==w[1]){
			cout<<"1";
			if(q[2]>=0&&q[2]<=2&&w[2]>=0&&w[2]<=2){
				cout<<"1";
				if(abs(q[2]-w[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(q[2]>=3&&q[2]<=4&&w[2]>=3&&w[2]<=4){
				cout<<"1";
				if(abs(q[2]-w[2])==1){
					cout<<"1";
				}
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
