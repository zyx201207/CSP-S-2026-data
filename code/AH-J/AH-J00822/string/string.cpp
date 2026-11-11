#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans,len=1;
char c[200005],zf[200005],st[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			zf[len]=c[i];
			len++;
		}
	}
	for(int i=1;i<=len;i++){
		st[i]=zf[len-i];
	}
	for(int i=1;i<=len;i++){
		if(st[i]!=zf[i]) ans++;
	}
	cout<<ans/2;
	return 0;
}

