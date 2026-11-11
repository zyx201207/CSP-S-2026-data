#include<bits/stdc++.h>
using namespace std;
string s;
string q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long m,sum=0;
	int n;
	cin>>n; 
	for(int i=0;i<n;i++){
		cin>>m;
		cin>>q;
		for(long long j=0;j<m;j++)s+=q;
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]==s[s.size()-i-1])sum++;
	}
	cout<<(s.size()/2-sum);
	return 0;
}
