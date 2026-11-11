#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2,ans="0000";
	cin>>a>>s1>>b>>s2;
	if(a==b){
		ans[0]='1';
		string t1=s1.substr(0,2),t2=s2.substr(0,2);
		char x1=s1[2],x2=s2[2];
		if(t1==t2){
			ans[1]='1';
			if((x1>='A'&&x1<='C'&&x2>='A'&&x2<='C')||((x1=='D'||x1=='F')&&(x2=='D'||x2=='F'))){
				ans[2]='1';
				if(min(x1,x2)+1==max(x1,x2)) ans[3]='1';
			}
		}
	}
	cout<<ans;
	return 0;
}
