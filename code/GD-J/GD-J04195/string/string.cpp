#include<bits/stdc++.h>
using namespace std;
string s;
long long m,ss=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m;
	while(m--){
		long long a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	int n=s.size();
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1]){
			ss++;
		}
	}
	cout<<ss;
	return 0;
}
