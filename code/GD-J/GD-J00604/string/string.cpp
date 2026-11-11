#include<bits/stdc++.h>
using namespace std;

string str;
int n;
bool ishui(string s,int len){//判断是否为回文串 
	for(int i=0,j=len-1;i<len,j>=0;i++,j--){
		if(s[i]!=s[j]) return false;
	}
	return true;
}
int cf(string s){
	int len=s.size();
	if(len==1) return 0;//如果s不是单个字符，那么它一定是由下面的字符拼接而成 
	string ss1,ss2;
	for(int i=0;i<len-1;i++){
		ss1+=s[i];
		ss2+=s[i+1];
	}
	cout<<ss1<<" "<<ss2<<endl;
	if(ishui(s,len))return min(cf(ss1),cf(ss2));
	else return min(cf(ss1),cf(ss2))+1;
}

int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		string c;
		cin>>a>>c;
		for(int i=1;i<=a;i++) str+=c;
	}
	if(ishui(str,str.size())){
		cout<<0;
		return 0;
	}
	cout<<cf(str);

	return 0;
}

