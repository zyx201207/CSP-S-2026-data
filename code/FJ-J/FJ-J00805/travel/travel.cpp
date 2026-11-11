#include<bits/stdc++.h>
using namespace std;
char ans[5];
string c1,s1,c2,s2,n1,n2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	s1=" "+s1,s2=" "+s2;
	for(int i=1;i<=2;i++) 
		n1+=s1[i],n2+=s2[i];
	if(c1!=c2){
		cout << "0000";
		return 0;
	}else ans[1]='1';
	if(n1==n2) ans[2]='1';
	else ans[2]='9';
	if(s1[3]=='A' || s1[3]=='B' || s1[3]=='C'){
		if(s2[3]=='D' || s2[3]=='F') ans[3]='9';
		else ans[3]='1';
	}else{
		if(s2[3]=='D' || s2[3]=='F') ans[3]='1';
		else ans[3]='9';
	}
	if(ans[3]=='9') ans[4]='9';
	else if(ans[2]=='1'){
		if(abs(s1[3]-s2[3])==1) ans[4]='1';
		else ans[4]='9';
	}else if(s1[3]==s2[3]){
		int a,b;
		a=a+(n1[0]-'0')*10,a=a+n1[1]-'0';
		b=b+(n2[0]-'0')*10,b=b+n2[1]-'0';
		if(abs(a-b)==1) ans[4]='1';
		else ans[4]='9';
	}else ans[4]='9';
	for(int i=1;i<=4;i++){
		if(i==3){
			if(ans[2]=='1' && ans[3]=='1') cout << '1';
			else cout << '0';
			continue; 
		}
		if(ans[i]=='9') cout << '0';
		else cout << '1';
	}
	return 0;
} 
/*
6
 1000000000 a
  1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b

*/
