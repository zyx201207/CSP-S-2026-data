#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m=0,ans=0;
char c[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int x=1;
	for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
	m+=a[i];
	for(int j=1;j<=a[i];j++){
		s[x]=c[i];
		x++;
	}
}
	for(int l=1,r=m;l<=r;l++,r--){
		if(s[l]!=s[r]) ans++;
	}
	cout<<ans;
	return 0;
}
