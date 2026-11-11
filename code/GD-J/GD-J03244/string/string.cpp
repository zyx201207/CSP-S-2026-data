#include<bits/stdc++.h>
using namespace std;
string sd(long long l,char a){
	string s;
	while(l--){
		s+=a;
	}
	return s;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long l;
	char a;
	string s;
	for(int i=0;i<n;i++){
		cin>>l>>a;
		s+=sd(l,a);
	}
	
	long long cnt=0,p=s.length()-1;
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[p--]){
			cnt++;
		}
	}

	cout<<cnt;
	return 0;

} 
