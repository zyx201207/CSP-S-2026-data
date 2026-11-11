#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char st[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=4;i++){
		st[i]='0';
	}
	if(c1==c2){
		st[1]='1';
 	}
	char p[5],q[5];
	for(int i=1;i<=3;i++){
		p[i]=s1[i-1];
		q[i]=s2[i-1];
	}
	if((p[1]==q[1] && p[2]==q[2]) && st[1]=='1'){
		st[2]='1';
		if((p[3]<'D' && q[3]<'D') || (p[3]>='D' && q[3]>='D')){
			st[3]='1';
			if((p[3]<'D' && q[3]<'D') && (abs(p[3]-q[3])==1)){
				st[4]='1';
			}else if((p[3]>='D' && q[3]>='D') && (abs(p[3]-q[3])==2)){
				st[4]='1';
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<st[i];
	}
	return 0;
}
