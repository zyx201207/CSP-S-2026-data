#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char c;
		cin>>c;
		for(int i=1;i<=x;i++){
			s+=c;
			//cout<<c;
		}
	}
	//cout<<s.size();
	int l=0;
	int r=s.size()-1;
	int ans=0;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
		
	}
	cout<<ans;
	
	
	return 0;
} 
