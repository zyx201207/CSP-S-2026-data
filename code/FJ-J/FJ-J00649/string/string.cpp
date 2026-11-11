#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,m,v;
char c[200005],f[10000005],f2[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			f[++m]=c[i];
		}
	}
	for(int i=m;i>=1;i++){
		f2[++v]=f[i];
	}
	for(int i=1;i<=m;i++){
		if(f[i]!=f2[i])ans++;
	}
	cout<<ans/2;
	return 0;
}
