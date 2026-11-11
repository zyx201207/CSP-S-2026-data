#include<bits/stdc++.h>
using namespace std;
//Trick||Treat!
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	ll res=0;
	for(int i=0;i<n;i++){
		int x;
		char c;
		cin>>x>>c;
		res+=x;
		for(int j=0;j<x;j++)s+=c;

	}
	bool f=1;
	int ans=0,res1=res;
	for(int i=0;i<res/2;i++){
		if(s[i]!=s[res1-i-1]){
			f=0;
			break;
		}
	}
	if(f==1){
		cout<<0;
		return 0;
		
	}
	for(int i=0;i<res/2;i++){
		if(s[i]!=s[res1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
