#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		if(s2[1]==s4[1]&&s2[0]==s4[0]){
			cout<<1;
			int t1=s2[2]-'A',t2=s4[2]-'A';
			if((t1<=2&&t2<=2)||(t1>=3&&t2>=3)){
				cout<<1;
				if(t1-t2==1||t1-t2==-1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
