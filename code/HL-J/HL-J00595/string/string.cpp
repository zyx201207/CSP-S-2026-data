#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char b[10010];
	char c[10010];
	long long a[10010];
	long long n;
	long long ans=0,cnt=0,mj=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		cnt+=a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=cnt;j++){
			if(j>a[i]) break;
			mj++;
			c[mj]=b[i];
		} 
	}
	for(long long i=1;i<=cnt;i++){
		if(c[i]!=c[cnt+1-i]) ans++;
	}
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
