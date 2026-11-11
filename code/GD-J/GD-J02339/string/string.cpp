#include<bits/stdc++.h>
using namespace std;
struct data{
	long long a;
	string c;
}d[300000];
string s;
string t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","out",stdout);
	long long n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>d[i].a>>d[i].c;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=d[i].a;j++){
			s+=d[i].c;
		}
	}
	long long ans=0;
	for(int i=0;i<s.size()/2+1;i++){
		t[i]=s[s.size()-1-i];
		if(t[i]!=s[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

