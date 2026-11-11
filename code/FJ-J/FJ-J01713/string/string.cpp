#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,sum=0;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s=s+c;
		}
	}
	string s1=s;
	reverse(s.begin(),s.end());
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s1[i])sum++; 
	}
	cout<<sum; 
	return 0;
}
