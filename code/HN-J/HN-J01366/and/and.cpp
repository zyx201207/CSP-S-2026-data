#include<bits/stdc++.h> 
using namespace std;
long long n,m,maxn,k[1000001],op=1,mb=0;
long long qi(long long be){
	mb=(mb&k[be+1]);
	if(op==m){
		return mb;
	}
	else{
		op++;
		return qi(++be);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	sort(k+1,k+1+n);
	if(m==1){
		cout<<k[n];
		return 0;
	}
	for(long long i=1;i<=(n-m+1);i++){
		op=1;
		mb=k[i];
		maxn=max(qi(i),maxn);
	}
	cout<<maxn;
	return 0;
}
