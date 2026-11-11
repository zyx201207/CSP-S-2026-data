#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
string x1,y1,x2,y2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>y1>>x2>>y2;
	if(x1!=x2)ans+="0000";
	else ans+='1';
	if(y1[0]==y2[0]&&y1[1]==y2[1])ans+='1';
	else ans+="000";
	if(y1[2]<='C'&&y2[2]<='C'||y1[2]>='D'&&y2[2]>='D')ans+='1';
	else ans+="00";
	if(ans[2]=='1'&&abs(long(y1[2]-y2[2]))==1)ans+='1';
	else ans+='0';
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
