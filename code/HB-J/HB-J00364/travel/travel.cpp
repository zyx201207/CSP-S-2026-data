#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag0=false,flag1=false,flag2=false,flag3=false;
	if(c1==c2)flag0=true;
	if(flag0){
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		flag1=true;
	}
	if(flag1==true){
		if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C'){
			flag2=true;
		}
		if(s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F'){
			flag2=true;
		}
	}
	if(flag2){
		if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C'){
			if(abs(  (s1[2]-'0')-(s2[2]-'0')  )==1){
				flag3=true;
			}
		}
		if(s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F'){
			if(abs(  (s1[2]-'0')-(s2[2]-'0')  )==1){
				flag3=true;
			}
		}
	}
}
	cout << flag0 << flag1 << flag2 << flag3;
	return 0;
}
