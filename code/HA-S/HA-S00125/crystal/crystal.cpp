#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500020],minn,maxn,zh=0;
struct nod{
	long long zhi,ds;
	bool pd;
}b[20000020];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	maxn=a[n];
	minn=a[1];
	for(int i=n;i>=1;i--){
		b[a[i]].zhi=a[n]-a[i];
		b[a[i]].ds+=1;
		b[a[i]].pd=true;
	}
	long long gs=0,zh=0;
	for(int i=minn;i<=maxn;i++){
		if(zh>m){
			zh-=gs;
			break;
		}
		if(b[i].pd) gs+=b[i].ds;
		zh+=gs;
	}
	cout<<gs;
	return 0;
}
















