//邦吧卡邦~
//爱丽丝要成为最厉害的OIer！
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c1,c2;
string s1,s2;
bool flag1,flag2,flag3,flag4;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		flag1=true;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			flag2=true;
			if((('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C')) || (('D'<=s1[2]&&s1[2]<='F')&&('D'<=s2[2]&&s2[2]<='F'))){
				flag3=true;
				if(abs(s1[2]-s2[2])==1&&(!(((s1[2]=='D')&&(s2[2]=='F'))||((s1[2]=='F'&&(s2[2]=='D')))))){
					flag4=true;
				}
			}
		}
	}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
