#include <bits/stdc++.h>
using namespace std;
long long n,m[200005],ans,t;
float k;
char s[200005],x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>x;
		for(int j=1;j<=m[i];j++){
			t++;
			s[t]=x;
		}
	}
	k=t;
	for(int i=1;i<=ceil(k/2);i++){
		int j=t-i+1;
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}


