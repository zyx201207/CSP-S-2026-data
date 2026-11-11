#include<bits/stdc++.h>
using namespace std;
string aa,ba,ab,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>aa>>ab>>ba>>bb;
	if(aa==ba){
		cout<<1;
		if(ab[0]==bb[0]&&ab[1]==bb[1]){
			cout<<1;
			if(ab[2]=='A'&&(bb[2]=='B'||bb[2]=='C')){
				cout<<1;
				if(bb[2]=='B'){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else if(ab[2]=='B'&&(bb[2]=='A'||bb[2]=='C')){
				cout<<1;
				if(bb[2]=='A'||bb[2]=='C'){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else if(ab[2]=='C'&&(bb[2]=='A'||bb[2]=='B')){
				cout<<1;
				if(bb[2]=='B'){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else if(ab[2]=='D'&&bb[2]=='F'){
				cout<<11;
				return 0;
			}
			else if(ab[2]=='F'&&bb[2]=='D'){
				cout<<11;
				return 0;
			}
			else{
				cout<<"00";
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
	return 0;
}
