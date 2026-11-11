#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=0,mr,ll,wr,rt;
struct node{
	long long c,n;
}s[500010];
struct nobe{
	long long c,n;
}c[500010];
bool cmp(node x,node y){
	return x.c>y.c;
}
bool cmb(nobe x,nobe y){
	return mr-x.n<mr-y.n;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i].n=i;
		c[i].n=1000000;
	}
	if(m<1e9+1){
		for(int i=1;i<=n;i++){
			s[a[i]].c++;
			c[a[i]].c++;
			c[a[i]].n=s[a[i]].n;
		}
		sort(s+1,s+500001,cmp);
		mr=s[1].n;ans=s[1].c;
		sort(c+1,c+500001,cmb);
		for(int i=1;i<=n;i++){
			long long np=mr-c[i].n;
			if(c[i].n==s[i].n||np<0)continue;
			if(m>=c[i].c*np){
				m-=c[i].c*np;ans+=c[i].c;
			}
			else{
				long long x=1;
				while(m>=np){
					m-=np;
					ans++;x++;
				}
			}
		}
	}
	else{
		long long i=0,cha=a[2]-a[1];
		while(m-i>=0&&ans<=n){
			ans++;
			m-=i;
			i+=cha;
		}
	}
	cout<<ans;
	return 0;
}
