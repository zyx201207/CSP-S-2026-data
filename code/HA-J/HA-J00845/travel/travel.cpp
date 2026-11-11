#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char l1,l2;
int tmp=0,bj=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		tmp=1;
	}else{
		cout<<"0";
		tmp=0;
	}
	if(tmp==1){
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			bj=1;
		}else{
			cout<<"0";
			bj=0;
		}
	}else{
		cout<<"0";
	}
	l1=s1[2];
	l2=s2[2];
	if(bj==1){
		if(l1=='A'){
			if(l2=='B' || l2=='C'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(l1=='B'){
			if(l2=='A' || l2=='C'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(l1=='C'){
			if(l2=='A' || l2=='B'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(l1=='D'){
			if(l2=='F'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(l1=='F'){
			if(l2=='D'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}else{
		cout<<"0";
	}
	if(bj==1){
		if(l1=='A'){
			if(l2=='B'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(l1=='B'){
			if(l2=='A' || l2=='C'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(l1=='C'){
			if(l2=='B'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(l1=='D'){
			if(l2=='F'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(l1=='F'){
			if(l2=='D'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}else{
		cout<<"0";
	}
	return 0;
}
