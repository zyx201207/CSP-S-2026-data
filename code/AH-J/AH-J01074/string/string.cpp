#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=0;j<a;j++) s+=b;
	}
	for(int i=0;i<((int)s.size()+1)/2;i++) if(s[i]!=s[s.size()-i-1]) sum++;
	cout<<sum;
	return 0;
}
