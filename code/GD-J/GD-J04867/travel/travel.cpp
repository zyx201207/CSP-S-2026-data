#include <bits/stdc++.h>
using namespace std;
string q[1],w,e[1],r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q[0]>>w>>e[0]>>r;
	if(q[0]==e[0]){
		cout<<"1";
		int p=0;
		for(int i=0;i<2;i++){
			if(w[i]==r[i]){
				p++;
			}else{
				break;
			}
		}
		if(p==2){
			cout<<"1";
			if((w[2]=='A'&&(r[2]=='B'||r[2]=='C'))||(w[2]=='B'&&(r[2]=='A'||r[2]=='C'))||(w[2]=='C'&&(r[2]=='A'||r[2]=='B'))||(w[2]=='D'&&r[2]=='F')||(w[2]=='F'&&r[2]=='D')){
				cout<<"1";
				if(w[2]=='A'&&r[2]=='B'){
					cout<<"1";
				}else if(w[2]=='B'&&(r[2]=='B'||r[2]=='c')){
					cout<<"1";
				}else if(w[2]=='c'&&r[2]=='B'){
					cout<<"1";
				}else if(w[2]=='D'&&r[2]=='F'){
					cout<<"1";
				}else if(w[2]=='F'&&r[2]=='D'){
					cout<<"1";
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
 
