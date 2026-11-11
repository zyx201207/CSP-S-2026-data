#include <bits/stdc++.h>
using namespace std;
long long a[200005];
string c[200005];
int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);


	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long len=s.size();/*
	string sw="";
	for(int i=1;i<=len;i++){
		sw[i]=s[n-i+1];
	}
	cout<<sw<<endl;*/
	int cnt=0;
	for(int i=1;i<=len;i++){
		if(s[i]!=s[len-i+1]){
			cnt++;
		}
	}
	//cout<<s<<endl;
	cout<<cnt/2;


	return 0;
}

