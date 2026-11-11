#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool ans1,ans2,ans3,ans4;
char w1,w2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c)ans1=1;
	if(ans1&&b[0]==d[0]&&b[1]==d[1])ans2=1;
	w1=b[2],w2=d[2];
	if(ans2==1&&((w1<='C'&&w2<='C')||(w1>='D'&&w2>='D')))ans3=1;
	if(ans3==1&&(int)(abs(w1-w2))==1)ans4=1;
	cout<<ans1<<ans2<<ans3<<ans4;
	
	return 0;
}
