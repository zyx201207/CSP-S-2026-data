#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int i=1;i<=x;i++){
			s+=a;
		}
	}
	int sl=s.size();
	int cnt=0;
	for(int i=0;i<sl/2;i++){
		if(s[i]!=s[sl-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
