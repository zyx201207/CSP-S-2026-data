#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;string s="";
	cin>>n;bool f=1,f2=1;
	vector<char>c(n+1);
	vector<int>a(n+1);
	int mx=0;
	unsigned long long l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mx=max(mx,a[i]);
		if(c[i]!=c[i-1]&&i!=1)f=0;
		if(a[i]!=a[i-1]&&i!=1)f2=0;
		l+=a[i];
	}
	if(f){
		cout<<0;
		return 0;
	}
	if(f2){
		unsigned long long cnt=0;
		for(int i=1;i<=(n/2);i++){
			if(c[i]!=c[n+1-i])cnt+=a[i];
		}
		cout<<cnt;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++)s+=c[i];
		}
		unsigned long long cnt=0;
		for(unsigned long long i=0;i<(l/2);i++){
			if(s[i]!=s[l-i-1])cnt++;
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
//50000000
