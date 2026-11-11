#include<bits/stdc++.h>
using namespace std;
vector<char> a;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	if(n==1){cout<<0;return 0;}
	
	for(int i=0;i<n;i++){
		char c;
		int n;
		cin>>n;cin>>c;
		while(n--)a.push_back(c);
	}
	int ans=0;
	int ch1=0,ch2=0;
	for(int r=n-1,l=0;!(l>=r);++r && l--){
		if(a[r]!=a[l])ans++;
		
	}
	cout<<ans;
	return 0;
}
