#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[2]='1';
			if(s1[2]>='A'&&s1[2]<='C'){
				if(s2[2]>='A'&&s2[2]<='C'){
					ans[3]='1';
					n=abs(int(s1[2]-s2[2]));
					if(n==1){
						ans[4]='1';
					}else{
						ans[4]='0';
					}
				}else{
					ans[3]='0';
					ans[4]='0';
				}
			}else{
				if(s2[2]>='D'&&s2[2]<='F'){
					ans[3]='1';
					n=abs(int(s1[2]-s2[2]));
					if(n==1){
						ans[4]='1';
					}else{
						ans[4]='0';
					}
				}else{
					ans[3]='0';
					ans[4]='0';
				}
			}
		}else{
			ans[2]='0';
			ans[3]='0';
			ans[4]='0';
		}
	}else{
		ans[1]='0';
		ans[2]='0';
		ans[3]='0';
		ans[4]='0';
	}
	
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
}
