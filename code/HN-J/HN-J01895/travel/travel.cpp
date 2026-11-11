#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int flag1=0;
	if(c1==c2) flag1=1;
	cout<<flag1;
	int flag2=1; 
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]) flag2=0;
	}
	if(!flag1) flag2=0;
	cout<<flag2;
	int flag3=0;
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')) flag3=1;
	if(!flag2) flag3=0;
	cout<<flag3;
	int flag4=0; 
	if(flag3){
		if(abs(s1[2]-s2[2])==1) flag4=1;
	}
	cout<<flag4;
	return 0;
}
