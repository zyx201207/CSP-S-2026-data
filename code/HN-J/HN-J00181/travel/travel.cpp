#include<bits/stdc++.h>
using namespace std;
int ans[10];
bool d[10];
bool f(char a,char b){
	int aaa=0,bbb=0;
	d[a-'A']=d[b-'A']=1;
	for(int i=0;i<3;i++)
		if(d[i])
			aaa++;
	for(int i=3;i<5;i++)
		if(d[i])
			bbb++;
	d[a-'A']=d[b-'A']=0;
	if(aaa==2||bbb==2)
		return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		ans[1]=1;
	if(ans[1]&&s1.substr(0,2)==s2.substr(0,2))
		ans[2]=1;
	if(ans[2]&&f(s1[2],s2[2]))
		ans[3]=1;
	if(ans[3]&&abs(s1[2]-s2[2])==1)
		ans[4]=1;
	for(int i=1;i<=4;i++)
		cout<<ans[i];
	return 0;
}
