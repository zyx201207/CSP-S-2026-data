#include <bits/stdc++.h>
using namespace std;
bool flag1,flag2,flag3,flag4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		flag1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			flag2=1;
		}
		if(flag2){
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				flag3=1;
				int a,b;
				a=s1[2]-'A';
				b=s2[2]-'A';
				if(a-b==1||a-b==-1){
					flag4=1;
				}
			}
		}
		cout<<flag1<<flag2<<flag3<<flag4;
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}