#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cmath>	
using namespace std;//1<<j 2^j 
int n,m;
struct st{
	int a;
	int l;
	bool w[31];
}s[200005];
bool cmp (st x,st y){
	if(x.l==y.l)return x.a>y.a;
	return x.l>y.l;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
		int ll=0;
		for(int j=0;(1<<j)<=s[i].a;j++){
			s[i].w[j]=!((s[i].a&(1<<j))==0);
			ll+=s[i].w[j];
			
		}
		s[i].l=ll;
	}
	sort(s+1,s+1+n,cmp);
	int ans=s[1].a;
	for(int i=2;i<=m;i++){
		ans=ans&s[i].a;
	}
	cout<<ans;
	return 0;
}	/*
4 2
3 15 12 12
*/
