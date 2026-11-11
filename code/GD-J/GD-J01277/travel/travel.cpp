#include<bits/stdc++.h>
using namespace std;
string s11,s22,c11,c22;
string ans;
long long vis[10];
int main(){
	freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
	vis[0]=vis[1]=vis[2]=10;
	vis[5]=vis[3]=22;
	cin>>c11>>s11>>c22>>s22;
	if(c11==c22){
		ans+='1';
		if(s11[0]==s22[0]&&s11[1]==s22[1]){
			ans+='1';
			long long v=s11[2]-'A',u=s22[2]-'A';
			if(vis[v]==vis[u]&&vis[v]!=0){
				ans+='1';
				v++,u++;
				long long vv=min(v,u),uu=max(v,u);
				if((vv==1&&uu==2)||(vv==2&uu==3)||(vv==4&&uu==6))ans+='1';
				else ans+='0';
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else ans+="0000";
	cout<<ans;
	return 0;
} 
