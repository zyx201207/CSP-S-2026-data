#include<bits/stdc++.h>
using namespace std;
char c[7],s[9];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c[1]>>c[2]>>s[1]>>s[2]>>s[3]>>c[3]>>c[4]>>s[4]>>s[5]>>s[6];
	int l=s[3],r=s[6];
	if(c[1]==c[3]&&c[2]==c[4]){
		cout<<"1";
		if(s[1]==s[4]&&s[2]==s[5]){
			cout<<"1";
			if(s[3]>='A'&&s[3]<='C'){
				if(s[6]>='A'&&s[6]<='C'){
					cout<<"1";
					if(l+1==r||l-1==r){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
				else{
					cout<<"00";
				}
			}
			else{
				if(s[6]>='A'&&s[6]<='C'){
					cout<<"00";
				}
				else{
					cout<<"11";
				}
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
