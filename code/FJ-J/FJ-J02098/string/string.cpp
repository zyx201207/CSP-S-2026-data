#include <bits/stdc++.h>
using namespace std;
int n,ans,cnt,a[200005];
char c[200005],str[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) str[++cnt]=c[i];
	}
	for(int i=1;i<=cnt/2;i++)
		if(str[i]!=str[cnt-i+1])
			ans++;
	cout<<ans;
	return 0;
}
