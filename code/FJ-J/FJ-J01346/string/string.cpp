#include<bits/stdc++.h>
using namespace std;
long long m,ans;
char s[999999999];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=m+1;i<=m+a;i++){
			s[i]=c;
		}
		m+=a;
	}
	for(long long i=1;i<=m/2;i++){
		if(s[i]!=s[1+m-i]){
			ans++;
		}
	}
	cout<<ans;

	return 0;
}

