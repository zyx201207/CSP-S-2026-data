#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int z;
		cin>>z;
		string x;
		cin>>x;
		for(int j=1;j<=z;j++){
			s+=x;
		}
	}
	int q=0;
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]==s[s.size()-i-1]) continue;
		else q++;
	}
	cout<<q;
	return 0;
}
