#include<bits/stdc++.h>
using namespace std;
struct str{
	int x;
	char c;
}a[200005];
int n;
long long ans=0,l,r;
int read(){
	char c=getchar();
	int s=0,f=1;
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i].x=read();
		r+=a[i].x;
		cin>>a[i].c;
	}
	int n1=1,n2=n;
	while(l<=r){
		if(a[n1].c!=a[n2].c){
			int now=min(a[n1].x,a[n2].x);
			ans+=now;
			l+=now,r-=now;
			a[n1].x-=now,a[n2].x-=now;
			if(a[n1].x==0) n1++;
			if(a[n2].x==0) n2--;
		}else{
			int now=min(a[n1].x,a[n2].x);
			l+=now,r-=now;
			a[n1].x-=now,a[n2].x-=now;
			if(a[n1].x==0) n1++;
			if(a[n2].x==0) n2--;
		}
	}
	printf("%lld\n",ans);
}
