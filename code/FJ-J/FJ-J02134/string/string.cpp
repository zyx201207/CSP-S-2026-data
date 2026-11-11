#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("string3.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,left,right;
	int n;
	cin>>n;
	while(n--){
		int t;
		char c;
		cin>>t>>c;
		while(t--)s+=c;
	}
	for(int i=0;i<s.size()/2;i++)left+=s[i];
	for(int i=s.size()-1;i>=(s.size()+1)/2;i--)right+=s[i];
	int cnt=0;
	for(int i=0;i<right.size();i++){
		if(right[i]!=left[i])cnt++;
	}
	cout<<cnt;
	return 0;
}

