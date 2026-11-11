#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cnt=0;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		cnt+=x;
		char c;
		cin>>c;
		for(int j=0;j<x;j++) s+=c;
	}
	//cout<<s<<' ';
	//cout<<cnt<<' ';
	long long l=cnt/2,r=cnt/2;
	if(cnt%2==1) l--,r++;
	//cout<<l<<' '<<r<<' ';
	long long ans=0;
	while(l+1){
		if(s[l]!=s[r]) ans++;
		l--;
		r++;
	}
	cout<<ans;
	return 0;
}
