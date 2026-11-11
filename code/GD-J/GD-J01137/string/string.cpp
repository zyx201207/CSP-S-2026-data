#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(long long i=1,ii=a[i],j=n,jj=a[j];i<=j;){
		if(b[i]!=b[j]) ans+=min(ii,jj);
		long long t=min(ii,jj);
		ii-=t;
		jj-=t;
		if(ii==0) i++,ii=a[i];
		if(jj==0) j--,jj=a[j];
	}
	cout<<ans;
	return 0;
}
