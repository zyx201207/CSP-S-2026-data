//GZ-J00142 凯里市第一初级中学 周竣暄
#include <bits/stdc++.h>
using namespace std;
int main(){

	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);
	int c1,c2;
	char c3[5],c4[5];
	cin>>c1>>c3[5]>>c2>>c4[5];
	if(c1=c2){
		cout<<1;
		if(c3[0]==c4[0]){
			cout<<1;
			if(c3[2]=='D'&&c4[2]=='F'||c3[2]=='F'&&c4[2]=='D'||c3[2]=='A'&&c4[2]=='B'||c3[2]=='A'&&c4[2]=='C'||c3[2]=='B'&&c4[2]=='C'||c3[2]=='B'&&c4[2]=='A'||c3[2]=='C'&&c4[2]=='A'||c3[2]=='C'&&c4[2]=='B'){
				cout<<1;
				if(c3[2]=='D'&&c4[2]=='F'||c3[2]=='F'&&c4[2]=='D'||c3[2]=='A'&&c4[2]=='B'||c3[2]=='B'&&c4[2]=='C'||c3[2]=='B'&&c4[2]=='A'||c3[2]=='C'&&c4[2]=='B'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}

