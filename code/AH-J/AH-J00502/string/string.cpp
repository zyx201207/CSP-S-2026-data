#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5+100;
int n,a[MAXN];
char c[MAXN];
string s1[MAXN],s2[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int len=(n+1)/2;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s1[j]=c[i];
		}
	}
	for(int i=1;i<=len;i++){
		s2[i]=s1[n-i];
	}
	int ans=0;
	for(int i=1;i<=len;i++){
		if(s1[1]!=s2[i]) ans++;
	}
	cout<<ans;
	return 0;
}
