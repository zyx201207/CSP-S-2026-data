#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	while(n--){
		int x;
		string b;
		cin>>x>>b;
		while(x--){
			s+=b;
		}
	}
	//cout<<s<<endl;
	unsigned long long cnt=0;
	for(int i=0;i<=s.size()/2;++i){
		if(s[s.size()-1-i]!=s[i]){
			cnt++;
			s[s.size()-1-i]=s[i];
		}
		//cout<<s<<endl;
	}
	cout<<cnt;
	return 0;
}
