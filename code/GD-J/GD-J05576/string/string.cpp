#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,a,h=0,j=0;
	string s;
	char c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>c;
		while(a){
			s=s+c;
			a--;
		}
	}
	for(i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			h++;
		}
	}
	cout<<h;
	return 0;
}
