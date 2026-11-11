#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int l=4;
	string r1,r2;
	string x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
		l--;
		char w=r2[0];
		char s=r2[1];
		string r3;
		r3=w+s;
		w=x2[0];
		s=x2[1];
		string x3;
		x3=w+s;
		if(r3==x3){
			cout<<1;
			l--;
			if(r2[2]>='A'&&r2[2]<='C'&&x2[2]>='A'&&x2[2]<='C'||r2[2]>='D'&&r2[2]<='F'&&x2[2]>='D'&&x2[2]<='F'&&r2[2]!='E'&&x2[2]!='E'){
				cout<<1;
				l--;
				char o=min(r2[2],x2[2]),p=max(r2[2],x2[2]);
				if(p==o+1){
					cout<<1;
				}
				else{
					for(int i=1;i<=l;i++){
						cout<<0;
					}
					return 0;
				}
			}
			else{

				for(int i=1;i<=l;i++){
					cout<<0;
				}
				return 0;
			}
		}
		else{
			for(int i=1;i<=l;i++){
				cout<<0;
			}
			return 0;
		}
	}
	else{
		for(int i=1;i<=l;i++){
			cout<<0;
		}
		return 0;
	}
	return 0;
} 
