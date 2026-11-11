#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
bool huiwen(string s){
	for(int i=0;i<(s.size())/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			return 0; 
		}
	}
	return 1;
}
char c[1000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x>>c[i];
		sum+=x;
	}
	bool flag=1;
	for(int i=1;i<n/2;i++){
		if(c[i]!=c[n+1-i]){
			flag=0;
			break;
		}
	}
	if(flag) cout<<1;
	else{
		cout<<n/2;
	}
	return 0;
}
