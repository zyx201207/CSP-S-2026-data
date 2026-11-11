//GZ-J00508 敖翔 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s1,s2;
string ans; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s1>>m>>s2;
	if(n==m) ans=ans+'1';
	else ans=ans+'0';
	
	if(ans[0]=='0'){
		cout<<"0000"<<'\n';
		return 0;
	} 	
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]) ans=ans+'1';
	else ans=ans+'0';
	
	if(ans[1]=='0') {
		cout<<"1000"<<'\n';
		return 0;
	}
	
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&ans[1]=='1') ans=ans+'1';
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&ans[1]=='1') ans=ans+'1';
	else ans=ans+'0';
	
	if(ans[2]=='0'){
		cout<<"1100"<<'\n';
		return 0;
	}
	
	if((s1[2]-s2[2]==1||s1[2]-s2[2]==-1)&&ans[2]=='1') ans=ans+'1';
	else ans=ans+'0';
	
	cout<<ans<<'\n';
	return 0;
} 
