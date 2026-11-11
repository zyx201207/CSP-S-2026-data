#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c1,c2;
string s1,s2;
bool f;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2) {
		printf("1");
	} else {
		printf("0");
		f=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&!f) {
		printf("1");
	} else {
		printf("0");
		f=1;
	}
	if(s1[2]<='C'&&s2[2]<='C'&&!f) {
		printf("1");
	} else if(s1[2]>'C'&&s2[2]>'C'&&!f) {
		printf("1");
	} else {
		printf("0");
		f=1;
	}
	if(s1[2]-s2[2]==1&&!f){
		printf("1");
	}else if(s2[2]-s1[2]==1&&!f){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}

