#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
int n,k;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	int a;
	char c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s[++k]=c;
	}
	long long ans=0;
	for(int i=1;i<=k/2;i++){
		if(s[i]!=s[k-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}

