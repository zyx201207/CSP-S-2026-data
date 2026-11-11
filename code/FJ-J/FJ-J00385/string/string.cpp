#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s,ans,cnt,f[400005],p=1,siz;
struct node{
	int x,f;
	char c;
}a[400005],b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].x>>b[i].c;
		s+=b[i].x;
		b[i].f=s;
		f[i]=s;
	}
	for(int i=1;i<n;i++){
		f[i+n]=s-f[i];
	}
	sort(f+1,f+n*2);
	siz=unique(f+1,f+n*2)-f-1;
	for(int i=1;i<=n;i++){
		int last=b[i-1].f;
		while(p<=siz&&f[p]<=b[i].f){
			a[++cnt].x=f[p]-last;
			last=f[p];
			a[cnt].c=b[i].c;
			p++;
		}
	}
	for(int i=1;i<=cnt/2;i++){
		if(a[i].c!=a[cnt-i+1].c)ans+=a[i].x;
	}
	cout<<ans;
	return 0;
}
