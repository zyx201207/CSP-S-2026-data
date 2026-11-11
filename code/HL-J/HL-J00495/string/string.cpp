#include<bits/stdc++.h>
using namespace std;
long long L[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int cnt=0;
	string s,c;
	int n,a;
	cin>>n;
	cin>>a>>c;
	for(int i=1;i<=n;i++){
		s[i]=s[i]+1-i;
		cnt++;
	}
	cout<<cnt;
	return 0;
}
