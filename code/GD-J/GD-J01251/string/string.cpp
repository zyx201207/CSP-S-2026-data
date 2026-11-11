#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	long long cnt=0;
	if(s.size()%2==1){
		for(int i=0;i<=s.size()/2;i++){
			if(!(s[i]==s[s.size()-i-1])){
				cnt++;
			}
		}
	}else{
		for(int i=0;i<s.size()/2;i++){
			if(!(s[i]==s[s.size()-i-1])){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
