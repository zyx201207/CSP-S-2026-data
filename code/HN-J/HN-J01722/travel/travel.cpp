#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,x1,r2,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
		for(int i=0;i<2;i++){
			if(r2[i]!=x2[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<1;
		if(r2[2]=='A'){
			if(x2[2]=='B'||x2[2]=='C'){
				cout<<1;
				if(x2[2]=='B')
					cout<<1;
				else
					cout<<0;
			}	
			else
				cout<<"00";
		}
		else if(r2[2]=='B'){
			if(x2[2]=='A'||x2[2]=='C')
				cout<"11";
			else
				cout<<"00";
		}
		else if(r2[2]=='C'){
			if(x2[2]=='A'||x2[2]=='B'){
				cout<<1;
				if(x2[2]=='B')
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<"00";
		}
		else if(r2[2]=='D'){
			if(x2[2]=='F')
				cout<<"11";
			else
				cout<<"00";
		}
		else{
			if(x2[2]=='D')
				cout<<"11";
			else
				cout<<"00";
		}
	}
	else
		cout<<"0000";
	return 0;
}
