#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
int n;
long long a,p=1;
char b;
char s[1000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s[p]=b;
			p++;
		}
	}
	for(int i=1;i<=p/2;i++){
		if(s[i]!=s[p-i]) cnt++;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	cout<<cnt;
	return 0;
} 
