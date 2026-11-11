#include<bits/stdc++.h>
using namespace std;
int get_ans(string s){
	int l=0,r=s.size()-1;
	int ans=0;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++,r--;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string in_put="";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char c;
		cin>>c;
		for(int j=1;j<=x;j++){
			in_put+=c;
		}
	}
	cout<<get_ans(in_put);
	return 0;
} 
