#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct edge{
	long long a,b;
}d[N];
int n,m;
long long qpow[N],ans=0;
bool cmp(edge x,edge y){
	if(x.a==y.a)
		return x.b>y.b;
	return x.a>y.a;
}
bool cmp2(edge x,edge y){
	if(x.b==y.b)
		return x.a>y.a;
	return x.b>y.b;
}
long long one(long long x){
	int l=log2(x);
	long long cnt=0;
	while(l>=0){
		if(x>=qpow[l]){
			cnt++;
			x-=qpow[l];
		}
		l--;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	qpow[0]=1;
	for(int i=1;i<=30;i++)
		qpow[i]=qpow[i-1]*2;
	cin>>n>>m;
	bool p=true;
	for(int i=1;i<=n;i++){
		cin>>d[i].a;
		if(d[i].a!=i-1)
			p=false;
		d[i].b=one(d[i].a);
	}
	if(p)
		sort(d+1,d+n+1,cmp);
	else
		sort(d+1,d+n+1,cmp2);
	ans=d[1].a;
	for(int i=2;i<=m;i++)
		ans=ans&d[i].a;
	cout<<ans;
	return 0;
} 
