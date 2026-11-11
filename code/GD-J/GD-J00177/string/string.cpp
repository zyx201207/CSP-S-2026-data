#include<bits/stdc++.h>
using namespace std;
int solve(string str){
	string ck;
	int cnt=0;
	for(int i=str.length()-1;i>=0;i--){
		ck+=str[i];
	}
	if(ck==str)return 0;
	else return 1;	
}
int solve2(string zm,string zm2,string str){
	char last=str[0];
	int ans,cnt=0;
	string sv;
	for(int i=0;i<str.length();i++){
		if(str[i]!=last){
			ans=str.length()-i;
			break;
		}
		last=str[i];
	}if(ans>str.length()/2){
		sv=zm;
	}else sv=zm2;
	for(int i=0;i<str.length();i++){
		if(str[i]==sv[0]){
			cnt++;
		}
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s,smax=0,smin=10000;
	cin>>n;
	string zm,zm2;
	string str,a;
	for(int i=1;i<=n;i++){
	cin>>s>>a;
	if(s>smax)smax=s;zm=a;
	if(s<smin)smin=s;zm2=a;
	for(int j=0;j<s;j++){
		str=str+a;
		}
	}
	if(solve(str)==0){
	cout<<0;
	return 0;
	}cout<<solve2(zm,zm2,str);
	return 0;
}
