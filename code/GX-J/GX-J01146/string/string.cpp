#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string back(string s){
	string tmp="";
	for(int i=s.size();i>=0;i--)tmp+=s[i];
	return tmp;
	}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,tmp;
	cin>>n;
	string s="";
	char tmps;
	for(int i=0;i<n;i++){
		cin>>tmp>>tmps;
		for(int j=0;j<tmp;j++){
			s+=tmps;
		}
	}
	if(back(s)==s){
		cout<<0;
	}else{
		string a=back(s);
		int ans=0;
		for(int i=0;i<s.size();i++)if(s[i]!=a[i])ans++;
		cout<<ans;
	}
	return 0;
}
