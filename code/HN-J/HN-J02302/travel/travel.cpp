#include<bits/stdc++.h>
using namespace std;
char b[10],d[10],flag[5];
string a,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		flag[0]='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			flag[1]='1';
			if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E'){
				flag[2]='1';
				if(d[2]==b[2]+1||d[2]==b[2]-1){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
