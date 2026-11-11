#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string ans[10]={"0","0","0","0","0"};
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]="1";
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				ans[2]="1";
				if(s1[2]=='D'||s2[2]=='D'){
					ans[3]="1";
				}else if(s1[2]=='B'||s2[2]=='B'){
					ans[3]="1";
				}
			}
		}
	}
	for(int i=0;i<=3;i++){
		cout<<ans[i];
	}
	return 0;
}