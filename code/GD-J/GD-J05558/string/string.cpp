#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		while(x--){
			s+=c;
		}
	}
	if(s.size()%2==1){
	for(int i=0;i<s.size()/2;i++){
		s1+=s[i];
	}
	long long cnt=0,a=0;
	for(int i=s.size()-1;i>s.size()/2;i--){
		if(s1[a]!=s[i]){
			cnt++;
		}
		a++;
	}
	cout<<cnt;
	}else{
		for(int i=0;i<s.size()/2;i++){
		s1+=s[i];
	}
	int cnt=0,a=0;
	for(int i=s.size()-1;i>=s.size()/2;i--){
		if(s1[a]!=s[i]){
			cnt++;
		}
		a++;
	}
	cout<<cnt;
	}
	return 0;
}


