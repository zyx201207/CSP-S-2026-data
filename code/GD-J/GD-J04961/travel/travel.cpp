#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
		char c1=s2[2],c2=s4[2];
		s2.erase(s2.end()-1),s4.erase(s4.end()-1);
		if(s2==s4){
			cout<<"1";
			if(c1<'D'&&c2<'D'||c1>'C'&&c2>'C'){
				cout<<"1";
				if(abs(c1-c2)==1)
					cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
