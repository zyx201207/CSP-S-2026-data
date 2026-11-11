#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		char q;
		cin>>q;
		for(int i=0;i<m;i++){
			s+=q;
		}
	}
	int sum=0;
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]) sum++;
	}
	cout<<sum;
	return 0;
}
