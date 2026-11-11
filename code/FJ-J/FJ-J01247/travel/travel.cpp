#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans[5];
map<char,bool> mp;
int cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])	ans[1]=1;
	if(ans[1]==1&&s1[0]==s2[0]&&s1[1]==s2[1])	ans[2]=1;
	if(ans[1]==1&&ans[2]==1){
		mp[s1[2]]=1,mp[s2[2]]=1;
		if(mp['D']==1&&mp['F']==1)	ans[3]=1,ans[4]=1;
		if(mp['A']==1)	cnt++;
		if(mp['B']==1)	cnt++;
		if(mp['C']==1)	cnt++;
		if(cnt==2){
			ans[3]=1;
			if(mp['A']==1&&mp['B']==1)	ans[4]=1;
			if(mp['B']==1&&mp['C']==1)	ans[4]=1;
		}	
		
	}
	for(int i=1;i<=4;i++)	cout<<ans[i];
	return 0;
}