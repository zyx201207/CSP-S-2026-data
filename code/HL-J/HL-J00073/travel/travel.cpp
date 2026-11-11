#include<bits/stdc++.h>
using namespace std;
char c1[5],c2[5],c3[5],c4[5];
int ans[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ans[1]=ans[2]=ans[3]=ans[4]=1;
	cin>>(c1+1)>>(c2+1)>>(c3+1)>>(c4+1);
	for(int i=1;i<=2;i++){
		if(c1[i]!=c3[i]){
			ans[1]=0;ans[2]=0;ans[3]=0;ans[4]=0;
			break;
		}
	}
	for(int i=1;i<=2;i++){
		if(c2[i]!=c4[i]){
			ans[2]=0,ans[3]=0,ans[4]=0;
			break;
		}
	}
	int a=(int)c2[3]-64,b=(int)c4[3]-64;
	if(ans[3]==1){
		if((a<=3&&b<=3)||(a>4&&b>4)) ans[3]=1;
		else ans[3]=0;
	}
	if(abs(a-b)!=1) ans[4]=0;
	if((a==3&&b==4)||(a==4&&b==3)) ans[4]=0;
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
}