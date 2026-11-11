//GZ-J00308   ฐื๐ุบþะกังฮโณฟุ๊
#include <bits/stdc++.h>
using namespace std;
int a[1000005],c[1000005];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool p = 1;
	for(int i = 0; i<c1.size(); i++) {
		a[i] = c1[i]-'0';
	}
	for(int i = 0; i<c2.size(); i++) {
		if(c2[i]-'0' == a[i]) {
			p = 1;
		} else {
			p = 0;
			break;
		}
	}
	int sum = 0;
	if(p==1) {
		cout<<1;
		sum = 1;
	} else {
		cout<<0;
		sum = 0;
	}
	bool b = 1;
	for(int i = 0; i<s1.size()-1; i++) {
		c[i] = s1[i]-'0';
	}
	for(int i = 0; i<s2.size()-1; i++) {
		if(s2[i]-'0'==c[i]) {
			b=1;
		} else {
			b = 0;
			break;
		}
	}
	int cnt =0;
	if(b==1 && sum==1) {
		cout<<1;
		cnt = 1;
	} else {
		cout<<0;
		cnt = 0;
	}
	int su1=0,su2=0;
	for(int i = 0; i<s1.size(); i++) {
		if(s1[2]>='A' && s1[2]<='C'){
			su1 = 1;
			break;
		}else{
			su2 = 1;
		}
	}
	int su3 = 0,su4 = 0;
	for(int i = 0; i<s2.size(); i++) {
		if(s2[2]>='A' && s2[2]<='C'){
			su3 = 1;
			break;
		}else{
			su4 = 1;
		}
	}
	int ans = 0;
	if(cnt==1 && (su1==su3 || su2==su4)){
		cout<<1;
		ans = 1;
	}else{
		cout<<0;
		ans = 0;
	}
	bool k = 0;
	for(int i = 0; i<s1.size(); i++) {
		for(int j= 0; j<s2.size(); j++) {
			if((s1[2]=='A'&& s2[2]=='B') || (s1[2]=='B'&& s2[2]=='A') ||(s1[2]=='C'&& s2[2]=='B') ||(s1[2]=='B'&& s2[2]=='C')||(s1[2]=='D'&& s2[2]=='F') ||(s1[2]=='F'&& s2[2]=='D')) {
				k=1;
				break;
			} else {
				k=0;
				break;
			}
		}
		break;
	}
	if(k==1 && ans==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
