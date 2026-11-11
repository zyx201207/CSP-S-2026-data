#include<bits/stdc++.h>
using namespace std;
int n;
string s; 
int main(){
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++) s+=c;
	}
	int l=0,r=s.size()-1;
	bool flag=0;
	while(l<=r){
		if(s[l]!=s[r]){
			flag=1;
			break;
		}
		l++;
		r--;
	}
	if(flag==0) cout<<0;
	else{
		int cnt=0;
		while(l<=r){
			if(s[l]!=s[r]) cnt++;
			l++;
			r--;
		}
		cout<<cnt;
	}
	return 0;
}

