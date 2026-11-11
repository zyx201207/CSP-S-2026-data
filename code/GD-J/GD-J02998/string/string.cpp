#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	for(int i=0;i<n;i++){
		int a;
		char x;
		cin>>a>>x;
		for(int i=0;i<a;i++){
			s+=x;
		}
	}
	long long sum=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])sum++;
	}
	cout<<sum;
	return 0;
}

