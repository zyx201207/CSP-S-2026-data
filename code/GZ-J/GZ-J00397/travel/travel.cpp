//GZ-J00397 张颜淏 贵阳市云岩区中天中学 
#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(abs((int)s1[2]-s2[2])==1)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

