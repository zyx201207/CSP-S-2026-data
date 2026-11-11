#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		int m=(s1[0]-'0')*10+(s1[1]-'0');
		int n=(s2[0]-'0')*10+(s2[1]-'0');
		if(m!=n){
			cout<<"000";
		}else{
			cout<<"1";
			int a=(s1[2]-'A'+1),b=(s2[2]-'A'+1);
			int c=(a==1||a==2||a==3 ? 1:2),d=(b==1||b==2||b==3?1:2);
			if(c!=d){
				cout<<"00";
			}else{
				cout<<"1";
				if(c==1){
					if(abs(a-b)==1)cout<<"1";
					else cout<<"0";
				}else{
					cout<<"1";
				}
			}
			
		}
	}
	return 0;
}

