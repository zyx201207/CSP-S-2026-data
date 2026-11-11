#include<bits/stdc++.h>
using namespace std;
string s="";
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int z=0;z<n;z++){
		long long l;
		char a;
		cin>>l>>a;
		while(l--)
			s=s+a;
	}
	long long l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r])
			ans++;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
