#include<bits/stdc++.h>
using namespace std;
string s1,s2,c2a,c1a,p1,p2;
int c1,c2;
bool flag = true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else {
		cout<<"0000";
		flag = false;
	}
	c1a[0]=s1[0];
	c1a[1]=s1[1];
	c2a[0]=s2[0];
	c2a[1]=s2[1];
	if(flag){
		if(c2a[1]==c1a[1]&&c2a[0]==c1a[0]){
			cout<<"1";
		}
		else {
			cout<<"000";
			flag = false;
		}
	}
	p1=s1[2];
	p2=s2[2];
	if(flag){
		if(p1=="F"||p1=="D"){
			if(p2=="F"||p2=="D"){
				cout<<"1"<<"1";
			}
			else{
				cout<<"0"<<"0";
			}
		}
		else if(p2=="F"||p2=="D"){
			cout<<"0"<<"0";
		}
		else{
			cout<<"1";
			if(p1=="B"||p2=="B"){
				cout<<"1";
			}
		else{
			cout<<"0";
			}
		}
	}
	return 0;
}
