#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int a[N];char b[N],s[100000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		while(a[i]--)s[++m]=b[i];
	}
	for(int i=1;i<=m;i++)
		ans+=(s[m-i+1]!=s[i]);
	cout<<ans/2;
}
