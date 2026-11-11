#include<bits/stdc++.h>
using namespace std;
string s;
int sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	long long len=s.size()-1;
	for(int i=len;i>len/2;i--){
		if(s[len-i]!=s[i]) sum++;
	}
	cout<<sum;
	return 0;
}
