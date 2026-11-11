#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxn=2e5+5;
string s=" ";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sl=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int li;
		char ci;
		cin>>li>>ci;
		for(int j=1;j<=li;j++){
			s=s+ci;
		}
		sl+=li;
	}
	int sum=0;
	for(int i=1;i<=sl/2;i++){
		if(s[sl-i+1]!=s[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
