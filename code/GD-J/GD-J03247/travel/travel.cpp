#include<bits/stdc++.h>
using namespace std;
#define int long long
int c1,c2;string s1, s2;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;//同一车厢 
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;//同一排 
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
				cout<<1;//同一侧 
				if(s1[2]=='A'&&s2[2]=='C'){//不相邻 
					cout<<0;
				}else if(s1[2]=='C'&&s2[2]=='A'){//不相邻 
					cout<<0;
				}else{//相邻 
					cout<<1;
				}
			}else if(s1[2]=='D'&&s2[2]=='F'){
				cout<<"11";
			}else if(s1[2]=='F'&&s2[2]=='D'){
				cout<<"11";
			}
			else{//不在同一侧 
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
