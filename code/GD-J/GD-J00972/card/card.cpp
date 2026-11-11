#include<bits/stdc++.h>
using namespace std;
string c;
long long n;
bool cheak(string s,long long k){
	for(long long i=0;i<=s.size();i++){
		if(s[i]==k){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		char k=to_string(x);
		c+=k;
	}
	for(int i=1;i<=m;i++){
		long long cnt=0;
		string k;
		for(int j=1;j<=n;j++){
			k+=c.substr(0,1);
			if(check(k,i)==1) cnt++;
		}
		cout<<cnt<<' ';
	}
	return 0;
}
