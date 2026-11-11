#include<bits/stdc++.h>
using namespace std;
string s,s2;
int a,b,zw,zw2;
bool tf[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a;
	cin>>s;
	if(s[2]<=68)zw=s[2]-'A'+1;
	else zw=5;
	cin>>b;
	cin>>s2;
	if(s[2]<=68)zw2=s2[2]-'A'+1;
	else zw2=5;
	if(a==b){
		tf[0]=1;
		if(s[0]==s2[0]&&s[1]==s2[1]){
			tf[1]=1;
			if((max(zw,zw2)<4&&min(zw,zw2)<4)||(max(zw,zw2)>3&&min(zw,zw2)>3)){
				tf[2]=1;
				if(zw+1==zw2||zw-1==zw2)tf[3]=1;
			}
			
		}
		
	}
	for(int i=0;i<=3;++i){
		cout<<tf[i];
	}
	return 0;
}
