#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++)s+=b;
	}
	int l=s.size();
	int j=l-1;
	long long sum=0;
	for(int i=0;i<l;i++){
		if(s[i]!=s[j])sum++;
		j--;
	}
	cout<<sum/2;
	return 0;
}
