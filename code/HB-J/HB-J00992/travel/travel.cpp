#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
bool flag=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(r2[0]==x2[0]&&r2[1]==x2[1]&&r1==x1){
		cout<<1;
		if(r2[2]>='A'&&r2[2]<='C'&&x2[2]>='A'&&x2[2]<='C'){
			cout<<1;
			if(abs(r2[2]-x2[2])==1){
				cout<<1;
			}
			else{
				cout<<0;
			}
			flag=1;
		}
		else if((r2[2]=='D'&&x2[2]=='F')||(r2[2]=='F'&&x2[2]=='D')){
			cout<<1;
			if(abs(r2[2]-x2[2])==2){
				cout<<1;
			}
			else{
				cout<<0;
			}
			flag=1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<"00";
	}
	if(!flag){
		cout<<0;
	}
	return 0;
}
