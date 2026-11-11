#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2,w1,w2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int m1,m2;
	m1=s1.size();
	m2=s2.size();
	for(int i=0;i<m1;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			w1=w1*10+s1[i]-'0';
		}
	}
	for(int i=0;i<m2;i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			w2=w2*10+s2[i]-'0';
		}
	}
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(w1==w2){
		cout<<1;
		if(s1[m1-1]=='A'||s1[m1-1]=='B'||s1[m1-1]=='C'){
			if(s2[m2-1]=='A'||s2[m2-1]=='B'||s2[m2-1]=='C'){
				cout<<1;
				if(s1[m1-1]=='A'&&s2[m2-1]=='B'||s1[m1-1]=='B'&&s2[m2-1]=='A'||s1[m1-1]=='C'&&s2[m2-1]=='B'||s1[m1-1]=='B'&&s2[m2-1]=='C'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			if(s2[m2-1]=='D'||s2[m2-1]=='E'){
				cout<<1;
				if(s1[m1-1]=='D'&&s2[m2-1]=='E'||s1[m1-1]=='E'&&s2[m2-1]=='D'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}
	}else cout<<"000";
	return 0;
}
