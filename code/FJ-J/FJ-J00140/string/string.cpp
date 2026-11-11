#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		string ch;
		cin>>num>>ch;
		for(int j=0;j<num;j++){
			s+=ch;
		}
	}
	//cout<<s<<" ";
	int mid=n/2;
	int len=s.length();
	int cnt=0;
	for(int i=0;i<=mid;i++){
		if(s[i]!=s[len-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;	
} 
