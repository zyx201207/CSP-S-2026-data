#include<iostream>
#include<string>

using namespace std;
int t;
string s="";
int cnt;//统计需要修改的字符数  
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	//拼接字符串s 
	for(int i=1;i<=t;i++){
		int n;
		char c;
		cin>>n>>c;
		for(int i=1;i<=n;i++)s+=c;
	}
	int len=s.length()/2;
	for(int i=0;i<=len;i++){
		if(s[i]!=s[s.length()-1-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
