//GZ-J00199 遵义市第一初级中学 刘致江 
#include<bits/stdc++.h>
using namespace std;
char Tong(char m){
	if(m=='A' || m=='B' || m=='C') return 'a';
	else return 'b';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			if(Tong(s1[2])==Tong(s2[2])){
				cout<<1;
				if(s1[2]+1==s2[2] || s2[2]+1==s2[1]){
					if(s1[2]=='C' && s2[2]=='D' || s1[2]=='D' && s2[2]=='C'){
						cout<<0;
					}else{
						cout<<1;
					}
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
