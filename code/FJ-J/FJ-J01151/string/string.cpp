#include"bits/stdc++.h"
using namespace std;
int n,sum=0;
string s;
int main(){
	//68 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		string s2;
		cin>>num>>s2;
		while(num--)
		s+=s2;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])sum++;
	}
	cout<<sum;
	return 0;
}
