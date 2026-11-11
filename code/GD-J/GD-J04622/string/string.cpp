#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,r;
	char c;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r>>c;
		for(int j=1;j<=r;j++) s=s+c;
	}
	int sum=0;
	for(int i=s.length()/2;i<s.length();i++){
		if(s[i]!=s[s.length()-i-1]) sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
