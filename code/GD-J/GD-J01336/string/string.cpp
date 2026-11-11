#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,sum=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	int l=s.length();
	for(int i=0;i<(l+1)/2;i++){
		if(s[i]!=s[l-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
