#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c1,c2,ans1=0,ans2=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		ans1=(s1[0]-'0')*10+s1[1]-'0';
		ans2=(s2[0]-'0')*10+s2[1]-'0';
		if(ans1!=ans2){
			cout<<"1000";
			return 0;
		}else{
			char ss1=s1[2],ss2=s2[2];
			if((ss1<='C'&&ss2>'C')||(ss1>'C'&&ss2<='C')){
				cout<<"1100";
				return 0;
			}else{
				if(ss1=='D'||ss2=='D'||ss1=='B'||ss2=='B'){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}
		}
	}
	return 0;
}
