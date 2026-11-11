#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=0;
	cin>>n;
	string s,a;
	for(int i=0;i<n;i++){
		int t;
		char b;
		cin>>t>>b;
		for(int i=0;i<t;i++){
			s.push_back(b);
			num++;
		}
		a.push_back(b);
	}
	if(n==1){
		cout<<"0";
	}
	int cnt=0;
	int ans;
	if(n==2){
		if(a[0]==a[1]){
			cout<<"0";
		}
		else{
			for(int i=1;i<s.size();i++){
				if(s[i]==s[i-1]){
					cnt++;
				}
			}
			ans=num-cnt;
			if(ans>=cnt){
				cout<<cnt;
			}
			else{
				cout<<ans;
			}
		}
	}
	else{
		cout<<s.size()/2;
	}
	return 0;
}
