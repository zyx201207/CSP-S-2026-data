#include<bits/stdc++.h>
using namespace std;

int n;
long long sum[200010];
char c[200010];
long long top;
char s[10000010];
long long cnt;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sum[i]>>c[i];
		for(int j=1;j<=sum[i];j++) s[++top]=c[i];
	}
	for(int i=1;i<=top/2;i++){
		if(s[i]!=s[top-i+1]) cnt++;
	}
	cout<<cnt;
	return 0;
}
