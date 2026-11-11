#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
vector<char> ans;
int a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie();
	
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<c1.size();i++){
		a=c1[i]-'0';
		b=c2[i]-'0';
		if(a==b)ans.push_back('1');
		else ans.push_back('0');
	}
	for(int i=1;i<s1.size()-1;i++){
		a=s1[i]-'0';
		b=s2[i]-'0';
		if(a==b)ans.push_back('1');
		else ans.push_back('0');
	}
	for(int i=2;i<s1.size();i++){
		if(s1[i]=='A')c=48;
		if(s1[i]=='B')c=49;
		if(s1[i]=='C')c=50;
		if(s1[i]=='D')c=51;
		if(s1[i]=='F')c=52;
		if(s2[i]=='A')d=48;
		if(s2[i]=='B')d=49;
		if(s2[i]=='C')d=50;
		if(s2[i]=='D')d=51;
		if(s2[i]=='F')d=52;
		if(c+1==d && d!=51){
			ans.push_back('1');
			ans.push_back('1');
		}
		else if(c+1!=d && d!=51){
			ans.push_back('1');
			ans.push_back('0');
		}
		else if(c+1!=d && d==51){
			ans.push_back('0');
			ans.push_back('0');
		}
	}
	for(int i=0;i<4;i++)cout<<ans[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
