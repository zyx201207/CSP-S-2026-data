#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
char ch1,ch2;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ch1=s1[2];
	s1[2]='\0';
	ch2=s2[2];
	s2[2]='\0';
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if((ch1>='A'&&ch1<='C'&&ch2>='A'&&ch2<='C')||(ch1>='D'&&ch1<='F'&&ch2>='D'&&ch2<='F')){
				cout<<1;
				if(ch2-1==ch1||ch1-1==ch2){
					cout<<1;
				}else{
					cout<<0;
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
