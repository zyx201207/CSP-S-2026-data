#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a1,a2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=s1[2];
	a2=s2[2];
	s1=s1[0]+s1[1];
	s2=s2[0]+s2[1];
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if((a1=='F' and a2=='D') or (a1=='D' and a2=='F')){
				cout<<"11";
			}
			else if(a1!='F' and a1!='D' and a2!='F' and a2!='D'){
				cout<<1;
				if(max(a1,a2)-min(a1,a2)==1){
					cout<<1;
				}
				else{
					cout<<0;
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

