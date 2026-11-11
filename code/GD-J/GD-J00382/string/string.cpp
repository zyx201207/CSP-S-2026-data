#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
long long n,a[N],b[N],e[N],ans;char c[N],d[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[n-i+1]=a[i];d[n-i+1]=c[i];
	}
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];b[i]+=b[i-1];
		e[i]=a[i];e[i+n]=b[i];
	}
	sort(e+1,e+1+n*2);
	int u=1,v=1;
	for(int i=1;i<=2*n;i++){
		if(e[i]==e[i-1])continue;
		int len=e[i]-e[i-1];
		while(a[u]<e[i])u++;
		while(b[v]<e[i])v++;
		if(c[u]!=d[v])ans+=len;
	}
	cout<<(ans>>1);
	return 0;
}
