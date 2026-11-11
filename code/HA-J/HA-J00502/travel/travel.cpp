#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	int p1=0,p2=0;
	char t1,t2;
	int len1=s1.size(),len2=s2.size();
	for(int i=0;i<len1;i++){
		if(isdigit(s1[i])){
			p1=p1*10+(s1[i]-'0');
		}
		else t1=s1[i];
	}
	for(int i=0;i<len2;i++){
		if(isdigit(s2[i])){
			p2=p2*10+(s2[i]-'0');
		}
		else t2=s2[i];
	}
	if(p1==p2){
		cout<<'1';
	}
	else cout<<'0';
	if((t1=='A'||t1=='B'||t1=='C')&&(t2=='A'||t2=='B'||t2=='C')||(t1=='D'||t1=='F')&&(t2=='D'||t2=='F')){
		if(p1==p2){
			cout<<'1';
		}
		else cout<<'0';
	}
	else cout<<'0';
	if(p1==p2){
		if((t1=='A'||t1=='B'||t1=='C')&&(t2=='A'||t2=='B'||t2=='C')||(t1=='D'||t1=='F')&&(t2=='D'||t2=='F')){
			if(t1=='A'&&t2=='B'||t1=='B'&&t2=='A'||t1=='B'&&t2=='C'||t1=='C'&&t2=='B'||t1=='D'&&t2=='F'||t1=='F'&&t2=='D'){
				cout<<'1';
			}
			else cout<<'0';
		}
		else cout<<'0';
	}
	else cout<<'0';
	return 0;
}
