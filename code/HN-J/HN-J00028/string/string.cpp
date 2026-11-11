#include <bits/stdc++.h>
using namespace std;
int n,cnt,x,ans;
char s,a[67676767];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>s;
		cnt+=x;
		for(int j=0;j<=x;j++) a[cnt+j]=s;
	}
	for(int i=0;i<n;i++){
		if(a[i]!=a[cnt-i]) ans++;
	}
	cout<<ans;
	return 0;
}
