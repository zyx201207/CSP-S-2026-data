#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=4;i++){
		if(b){
			if(i==1&&c1==c2){
				cout<<1;
				continue;
			}
			else if(i==2&&s1[0]==s2[0]&&s1[1]==s2[1]){
				cout<<1;
				continue;
			}
			else if(i==3){
				if(s1[2]<='C'&&s2[2]<='C'){
					cout<<1;
					continue;
				}
				else if(s1[2]>'C'&&s2[2]>'C'){
					cout<<1;
					continue;
				}
				else{
					cout<<0;
					b=false;
					continue;
				}
			}
			else if(i==4){
				if(s1[2]-1==s2[2]||s1[2]+1==s2[2]){
					cout<<1;
					return 0;
				}
			}
			else{
				b=false;
			}
		}
		cout<<0;
	}
	return 0;
}
