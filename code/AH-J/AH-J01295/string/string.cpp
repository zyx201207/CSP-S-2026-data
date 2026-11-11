#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	long long x=s.size()-1;
	long long ans=0;
	for(int i=0;i<x/2;i++){
		if(s[i]!=s[x-i]){
			ans++;
		}
	}
	cout<<ans;
    return 0;
}
