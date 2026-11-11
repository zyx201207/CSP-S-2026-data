#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	memset(ans,0,sizeof(ans));
	if(c1==c2){
		ans[1]=1;
		int x=(s1[0]-'0')*10+s1[1]-'0',y=(s2[0]-'0')*10+s2[1]-'0';
		if(x==y){
			ans[2]=1;
			int a=s1[2]-'A'+1,b=s2[2]-'A'+1;
			if((a<=3&&b<=3)||(a>=4&&b>=4)){
				ans[3]=1;
				if(abs(a-b)==1)ans[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++)cout<<ans[i];
	return 0;
}
