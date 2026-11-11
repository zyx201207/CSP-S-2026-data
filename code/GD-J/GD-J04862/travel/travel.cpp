#include <bits/stdc++.h>
using namespace std;
int main(){
	froepen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	int i=0,s1n=0,s2n=0;
	while('0'<=s1[i]&&s1[i]<='9'){
		s1n*=10;
		s1n+=s1[i]-'0';
		i++;
	}
	i=0;
	while('0'<=s2[i]&&s2[i]<='9'){
		s2n*=10;
		s2n+=s2[i]-'0';
		i++;
	}
	char rn=s1[2],xn=s2[2];
	if(c1==c2){
		cout<<1;
		if(s1n==s2n){
			cout<<1;
			if((rn=='A'&&xn=='B')||(rn=='A'&&xn=='C')||(rn=='B'&&xn=='A')||(rn=='C'&&xn=='A')||(rn=='B'&&xn=='C')
			||(rn=='C'&&xn=='B')||(rn=='D'&&xn=='F')||(rn=='F'&&xn=='D')){
				cout<<1; 
				if((rn=='A'&&xn=='B')||(rn=='B'&&xn=='A')||(rn=='B'&&xn=='C')||(rn=='C'&&xn=='B')||(rn=='D'&&xn=='F')||(rn=='F'&&xn=='D')){
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
	}else cout<<"0000";
	return 0;
} 
