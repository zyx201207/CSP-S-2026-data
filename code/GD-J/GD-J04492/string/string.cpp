#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	string s="";
	int t;
	char a;
	for(int i=0;i<n;i++){
		cin>>t>>a;
		for(int j=i;j<i+t;j++){
			s+=a;
		}
	}
	for(int i=0;i<s.size()-i-1;i++){
		if(s[i]==s[s.size()-i-1]) continue;
		else sum++;
	}
	cout<<sum<<endl;
	return 0;
}
