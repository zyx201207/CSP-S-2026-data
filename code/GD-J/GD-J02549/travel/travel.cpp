#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string ans="0000";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';
			int l=s1[2]-65+1,r=s2[2]-65+1;
			if(l<=3&&r<=3){
				ans[2]='1';
				if(abs(l-r)==1){
					ans[3]='1';
				}
			}else if(l>3&&r>3){
				ans[2]='1';
				if(abs(l-r)==1){
					ans[3]='1';
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
