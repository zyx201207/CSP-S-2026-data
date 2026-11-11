#include<bits/stdc++.h>
using namespace std;
int res[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		res[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			res[1]=1;
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				res[2]=1;
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
					res[3]=1;
				}
			}
			if((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')){
				res[2]=1;
				res[3]=1;
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<res[i];
	}
	return 0;
}
