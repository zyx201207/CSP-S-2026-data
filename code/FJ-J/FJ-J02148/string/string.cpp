#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n;
	long long a;
	long long ans=0;
	char b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b;
		} 
	}
	long long f=s.size();
	for(int i=0;i<=f/2-1;i++){
		if(s[i]!=s[f-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
