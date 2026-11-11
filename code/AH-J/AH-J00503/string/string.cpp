#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int g;
		string ss;
		scanf("%d ",&g);
		cin>>ss;
		for(int j=1;j<=g;j++){
			s+=ss;
		}
	}
	long long gai=0;
	for(int i=s.size()/2;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1])gai++;
	}
	cout<<gai;
	return 0;
}
