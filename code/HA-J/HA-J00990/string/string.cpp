#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
bool hui_wen(string ss){
	string s1;
	int j=0;
	for(int i=ss.size()-1;i>=0;i--){
		s1[j]=ss[i];
		j++;
	}
	for(int i=0;i<j;i++){
		if(s1[i]!=ss[i]){
			return 0;
		}
	}
	return 1;
}
string fan_zhuan(string sss){
	string ss1;
	for(int i=sss.size()-1;i>=0;i--){
		ss1+=sss[i];
	}
	return ss1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int k=1;k<=n;k++){
		long long a;
		string c;
		cin>>a;
		cin>>c;
		for(long long i=1;i<=a;i++){
			s+=c;
		}
	}
	if(hui_wen(s)==1){
		cout<<0;
		return 0;
	}else{
		string st=s.substr(0,s.size()/2);
		st=fan_zhuan(st);
		string st1;
		if(s.size()%2==0){
			st1=s.substr(s.size()/2,s.size()/2);
		}else{
			st1=s.substr(s.size()/2+1,s.size()/2);
		}
		for(int i=0;i<st.size();i++){
			if(st[i]!=st1[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
