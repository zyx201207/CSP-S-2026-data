#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	int l=0,r=s.length()-1;
	while(l<r){
		if(s[l]!=s[r]){
			cout<<s[l]<<" "<<s[r]; 
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
}
