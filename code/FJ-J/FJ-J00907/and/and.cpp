#include<bits/stdc++.h>
using namespace std;
long long a[200001],n,m,cnt,maxx;

void dg(long long q,long long dq){
	if(q>n){
		return ;
	}
	long long qd=dq;
	qd=dq&a[q];
	cnt++;
	if(cnt==m){
		cnt--;
		maxx=max(qd,maxx);
		return ;
	}
	for(int i = 1; i+q<=n; i++){
		dg(q+i,qd);
	}
	cnt--;
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>> n >> m;
	for(int i = 1; i<=n; i++){
		cin>> a[i];
	}
	dg(2,a[1]);
	cout<< maxx;
	return 0;
}
