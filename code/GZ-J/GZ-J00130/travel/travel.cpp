//GZ-J00130 凤冈县第二中学 罗迎甲 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a1,a2;
	string a,b;
	cin>>a1>>a>>a2>>b;
	if(a1==a2){
		cout<<"1";
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<"1";
			if((a[2]!='D'&&b[2]!='F')&&(a[2]!='F'&&b[2]!='D')){
				cout<<"1";
				if(a[2]==b[2]+1||a[2]==b[2]-1){
					cout<<"1";
					return 0;
				}else cout<<"0";
			}else if((a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')){
				cout<<"1";
				if(a[2]==b[2]+1||a[2]==b[2]-1){
					cout<<"1";
					return 0;
				}else cout<<"0";
			}else cout<<"00"; 
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
