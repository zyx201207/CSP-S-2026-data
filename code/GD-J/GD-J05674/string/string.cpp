#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=0,ans=0;
	char c;
	char s[500000];
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s[cnt]=c;
			cnt++;
		}
	}
	for (int i=0;i<(cnt-1)/2+1;i++){
		if (s[i]!=s[cnt-i-1]){
			ans++;
		}
	}
	cout<<ans;
} 
