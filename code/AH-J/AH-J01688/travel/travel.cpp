#include<bits/stdc++.h>
using namespace std;

int ans1,ans2,ans3,ans4;
string s1,s2;
char c1[50],c2[50];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cin>>s1;
	for(int i=0;i<3;i++) cin>>c1[i];
	cin>>s2;
	for(int i=0;i<3;i++) cin>>c2[i];
	if(s1==s2) ans1=1;
	else{
		cout<<ans1<<ans2<<ans3<<ans4;
		return 0;
	}
	ans2=1;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			ans2=0;
			cout<<ans1<<ans2<<ans3<<ans4;
			return 0;
		}
	}
	if(c1[2]=='A')
		if(c2[2]=='B'||c2[2]=='C') ans3=1;
	if(c1[2]=='B')
		if(c2[2]=='A'||c2[2]=='C') ans3=1;
 	if(c1[2]=='C')
		if(c2[2]=='B'||c2[2]=='A') ans3=1;
	if(c1[2]=='D'&&c2[2]=='E') ans3=ans4=1;
	if(c1[2]=='A'&&c2[2]=='B') ans4=1;
	if(c1[2]=='B'&&c2[2]=='C') ans4=1;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
