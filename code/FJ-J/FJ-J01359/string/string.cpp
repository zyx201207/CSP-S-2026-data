#include<bits/stdc++.h>
using namespace std;
	string s,s1;
	long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		long long x;
		cin>>x;
		string c;
		cin>>c;
		for(long long i=0;i<x;i++)s+=c;
	}
	int len=s.size();
	for(int i=0;i<(len+1)/2;i++)s1[i]=s[len-i-1];
	for(int i=0;i<(len+1)/2;i++){
		if(s[i]!=s1[i])ans++;
	}
	cout<<ans;
	return 0;
}
