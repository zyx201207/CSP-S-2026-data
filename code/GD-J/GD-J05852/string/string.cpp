#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,jishu=0;
	string s="";
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
	}
	long long chang=s.size();
	for(int i=0;i<chang/2;i++){
		if(s[i]!=s[chang-1-i]){
			jishu++;
		}
	}
	cout<<jishu;
	return 0;
} 
