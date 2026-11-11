//AC++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<climits>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#define int long long
using namespace std;
int c1,c2;
string s1,s2;
int f(string str){
	int len=str.length(),ans=0;
	for(int i=0;i<len;i++) 
		if(str[i]<='Z'&&str[i]>='A') return ans;
		else ans=ans*10+(str[i]-'0');
}
char g(string str){
	int len=str.length();
	return str[len-1];
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	
	int s01=f(s1),s02=f(s2);
	if(s01==s02) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	
	char s10=g(s1),s20=g(s2);
	
	if((s10<='C'&&s20<='C')||(s10>='D'&&s20>='D')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	
	if(s10>s20) swap(s10,s20);
	
	if(s10+1==s20) cout<<1;
	else cout<<0;
	
	return 0;
	
}
