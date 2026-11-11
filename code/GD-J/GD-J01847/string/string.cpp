#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y; 
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	int p1=0,p2=s.size()-1;
	while(p1<=p2){
		if(s[p1]!=s[p2]) cnt++;
		p1++,p2--;
	}
	cout<<cnt;
	return 0;
}
