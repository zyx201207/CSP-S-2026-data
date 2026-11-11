#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N],s[N];
ll read(){
	ll s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int p=0,ans=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		while(a[i]*(i-p)-(s[i]-s[p])>m)p++;
		ans=max(ans,i-p);
	}
	printf("%d",ans);
	return 0;
}