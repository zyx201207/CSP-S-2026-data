#include<bits/stdc++.h>
using namespace std;
int n,a[200005],cnt;
string s1,s,s2,s3;

string hw(string x){
	for(int i=s.size()-1;i>=0;i--){
		s2+=s[i];
	}
	s3=s2;
	return s2;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s1;
		for(int i=0;i<=a[i];i++){
			s+=s1;
		}
	}
	if(hw(s)==s){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(s[i]!=s3[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
