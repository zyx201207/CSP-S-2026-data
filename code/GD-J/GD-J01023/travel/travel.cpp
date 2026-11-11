#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
char ch[4];int cnt=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ch[0]='A';ch[1]='B';ch[2]='C';
	cin>>c1>>s1>>c2>>s2;
	ans[0]='0';ans[1]='0';ans[2]='0';ans[3]='0';
	if(c1==c2){
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';
			for(int i=0;i<4;i++){
				if(s1[2]==ch[i]){
					cnt++;
				}
				if(s2[2]==ch[i]){
					cnt++;
				}
			}
			if(cnt==2||cnt==0){
				ans[2]='1';
				if(s2[2]-1==s1[2]||s2[2]+1==s1[2]){
					ans[3]='1';
				}
			}
		}
	}
			
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
