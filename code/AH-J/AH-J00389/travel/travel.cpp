#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	char c1=s2[2],c2=s4[2];
	if(s1==s3){
		cout<<1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			cout<<1;
			if((c1>='A'&&c1<='C'&&c2>='A'&&c2<='C')||((c1=='D'&&c2=='F')||(c1=='F'&&c2=='D'))){
				cout<<1;
				if(c1+1==c2||c1-1==c2){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
