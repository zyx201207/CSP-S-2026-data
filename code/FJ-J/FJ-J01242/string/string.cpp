#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s01,s02;
	int n;
	char s2;
	long long t,count=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>s2;
		for(int j=1;j<=t;j++) s+=s2;
	}
	int a=s.size()/2;
	for(int i=0;i<a;i++) s01+=s[i];
	if(s.size()%2==1) a++;
	for(int i=s.size()-1;i>=a;i--) s02+=s[i];
	for(int i=0;i<s01.size();i++){
		if(s01[i]!=s02[i]) count++;
	}
	cout<<count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
