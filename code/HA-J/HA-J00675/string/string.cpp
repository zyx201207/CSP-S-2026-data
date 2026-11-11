#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n;//输入几次 
	string s = "";//用来接受字符串内容进行拼接 
	cin>>n;
	
	long long a;//用来接受输入的字母个数
	char b;//用来接收所添加的字符 
	for(long long i = 1;i <= n;i++){//进行字符串拼接 
		cin>>a>>b;
		for(long long j = 0;j < a;j++){
			s+=b;
		}
	}
	
	int gbcs = 0;//需要改变字符串的次数
	
	for(long long i = 0;i < s.size()/2;i++){
		if(s[i] != s[s.size()-1-i]){
			gbcs++;
		}
	} 
	
	cout<<gbcs;
	return 0;
}
