#include<bits/stdc++.h>
using namespace std;
int n,x,k,l;
string m,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>x>>y;
	if(m[2]=='A')k=1;
	if(y[2]=='A')l=1;
	if(m[2]=='B')k=2;
	if(y[2]=='B')l=2;
	if(m[2]=='C')k=3;
	if(y[2]=='C')l=3;
	if(m[2]=='D')k=4;
	if(y[2]=='D')l=4;
	if(m[2]=='F')k=5;
	if(y[2]=='F')l=5;
	if(n==x){
		cout<<1;
		if(m[0]==y[0]&&m[1]==y[1]){
			cout<<1;
			if(k>=4&&l>=4 || k<=3&&l<=3){
				cout<<1;
				if(k-l==1||k-l==-1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}

	return 0;
}
