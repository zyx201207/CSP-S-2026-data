#include <bits/stdc++.h>
using namespace std;
long long a[500005],num,Pa,Ps,n,m;
void d(long long p,long long s,long long maxx){
	if(Pa<Ps) return;
	if(p==n+1){
		num=max(num,maxx);
		return ;
	}
	if(a[p]+s>=Pa){
		d(p+1,s-a[p]+Pa,maxx+1);
	}
	d(p+1,s,maxx);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	Ps=a[1];
	Pa=a[n];
	d(1,m,0);
	cout<<num;
	return 0;
}
