#include <bits/stdc++.h>
using namespace std;
const int N=1000;
string c1,s1,c2,s2;
string ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string n1,n2;
	n1=s1[0]+s1[1];
	n2=s2[0]+s2[1];
	char l1,l2;
	l1=s1[2];
	l2=s2[2];
	if(c1==c2){
		ans[0]='1';
		if(n1==n2){
			ans[1]='1';
			if(l1<='C' and l2<='C'){
				ans[2]='1';
				if((l1=='A' and l2=='B') or (l1=='B' and l2=='C')){
					ans[3]='1';
				}
			}
			if(l1>='D' and l2>='D'){
				ans[2]='1';
				ans[3]='1';
			}
		}
	}
	cout<<ans<<"\n"; 
	return 0;
}
