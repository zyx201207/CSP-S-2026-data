#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000010
long long n,ans,size=1;
char s[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for (int j=1;j<=x;j++){
			s[size]=c;
			size++;
		}
	}
	int l=0,r=size;
	while (l<r){
		l++;r--;
		if (s[l]!=s[r]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
