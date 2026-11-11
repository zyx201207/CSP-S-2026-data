#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
char t1,t2;
int l1,l2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	t1=s1[2],t2=s2[2];
	for(int i=0;i<=1;i++)l1=l1*10+s1[i]-'0',l2=l2*10+s2[i]-'0';
	if(c1!=c2)cout<<"0000";
	else{
		if(l1!=l2)cout<<"1000";
		else{
			if('A'<=t1&&t1<='C'&&'D'<=t2&&t2<='F')cout<<"1100";
			else if('A'<=t2&&t2<='C'&&'D'<=t1&&t1<='F')cout<<"1100";
			else{
				if((t1=='A'&&t2=='B')||(t1=='B'&&(t2=='A'||t2=='C'))||(t1=='C'&&t2=='B')||(t1=='D'&&t2=='F')||(t1=='F'&&t2=='D'))cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
}
//HSY (tham&&hex233) new bee!
