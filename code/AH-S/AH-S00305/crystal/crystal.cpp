#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,cnt=0,sum=0;
long long a[500005];
queue<long long> s;
long long read(){
	char c;
	long long s=0,t=1;
	c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') t=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') s=s*10+c-'0',c=getchar();
	return s*t;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		while(!s.empty()&&a[i]*cnt-sum>m) sum-=s.front(),cnt--,s.pop();
		cnt++,sum+=a[i],s.push(a[i]);
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
}
