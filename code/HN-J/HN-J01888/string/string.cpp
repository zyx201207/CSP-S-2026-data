#include<bits/stdc++.h>
using namespace std;
long long n,m,x,ans;
char y;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int j=m;j<m+x;j++){
			s[j]=y;
		}
		m+=x;
	}
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
