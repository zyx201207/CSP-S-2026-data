#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans[10]={};
	string c1="";
	string s1="";
	string c2="";
	string s2="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]=1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			ans[1]=1;
			if(s1[2]!='C' or s2[2]!='D'){
				if(s1[2]!='D' or s2[2]!='C'){
					ans[2]=1;
					if(s1[2]+1==s2[2] or s1[2]-1==s2[2]){
						if(s2[2]+1==s1[2] or s2[2]-1==s1[2]){
							ans[3]=1;
						}
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}
