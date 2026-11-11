#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b){
	if(a>='A'&&a<='C'){
		return (b>='A'&&b<='C');
	}
	else if(a>='D'&&a<='F'){
		return (b>='D'&&b<='F');
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	int l1,l2;
	char r1,r2;
	cin>>c1>>s1>>c2>>s2;
	l1=s1[0]*10+s1[1];
	l2=s2[0]*10+s2[1];
	r1=s1[2];
	r2=s2[2];
	if(c1==c2){
		cout<<1;
		if(l1==l2){
			cout<<"1";
			if(check(r1,r2)){
				cout<<"1";
				if(abs(r1-r2)==1||(r1=='F'&&r2=='D')||(r2=='F'&&r1=='D')){
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
