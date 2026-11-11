#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool fun(){
	char a1=s1[2],a2=s2[2];
	if(a1=='A'&&(a2=='B'||a2=='C')) return 1;
	if(a1=='B'&&(a2=='A'||a2=='C')) return 1;
    if(a1=='C'&&(a2=='A'||a2=='B')) return 1;
    if(a1=='D'&&a2=='F') return 1;
    if(a1=='F'&&a2=='D') return 1;
    return 0;
}
bool fun1(){
    char a1=s1[2],a2=s2[2];
	if(a1=='A'&&a2=='B') return 1;
	if(a1=='B'&&(a2=='A'||a2=='C')) return 1;
    if(a1=='C'&&a2=='B') return 1;
    if(a1=='D'&&a2=='F') return 1;
    if(a1=='F'&&a2=='D') return 1;
    return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int t1=(s1[0]-'0')*10+(s1[1]-'0');
		int t2=(s2[0]-'0')*10+(s2[1]-'0');
		if(t1==t2){
			cout<<1;
			if(fun()){
				cout<<1;
				if(fun1()){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
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
