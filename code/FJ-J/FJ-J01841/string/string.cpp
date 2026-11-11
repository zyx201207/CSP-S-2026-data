#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	char s[2000000];
	cin >> n;
	int l=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin >> a >> c;
		for(int i=l;i<l+a;i++){
			s[i]=c;
		}
		l+=a;
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
