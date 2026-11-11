#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int i=1;i<=x;i++){
			s+=a;
		}
	}
	cout<<s;
	long long ans=0;
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
}

