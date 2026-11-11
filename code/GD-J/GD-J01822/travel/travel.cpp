#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans1,ans2,ans3,ans4;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans1=1;
	}
	else{
		ans1=0;
	}
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&ans1){
		ans2=1;
	}
	else{
		ans2=0;
	}
	if((s1[2]>='D'&&s2[2]>='D'||s1[2]<'D'&&s2[2]<'D')&&ans2){
		ans3=1;
	}
	else{
		ans3=0;
	}
	if((s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'||s1[2]+1==s2[2]||s1[2]-1==s2[2])&&ans3){
		ans4=1;
	}
	else{
		ans4=0;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}

