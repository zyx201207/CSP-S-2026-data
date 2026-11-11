#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,T[500086],K[506],X[100086],Y[100086],ans=0;
struct P{
	long long len, A[500086],t[500086];
	bool is(long long a){
		for(int i=0;i<len;i++) if(A[i]==a) return 1;
		return 0;
	}
	void C(long long k){
		len=k;
		for(long long j=0;j<len;j++){
			cin>>A[j]>>t[j];
		}
	}
} p[506];
long long l(long long a,long long b,long long x){
	for(long long i;i<n;i++){
		if(p[i].is(a)&&p[i].is(b)&&i!=x) return i;
	}
	return -1;
} 
long long IS(P a,P b,long long m){
	int L[500086],x=0;
	for(long long i=0;i<a.len;i++){
		if(b.is(a.A[i])) L[++x]=A[i];
	}
	if(m==-1) return x;
	else return L[m];
}
long long ISs(P a,long long m){
	int L[500086],x=0;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a.len;j++){
		if(p[i].is(a.A[j])) L[++x]=i;
	}
	}
	if(m==-1) return x;
	else return L[m];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=0;i<m;i++) cin>>T[i];
	for(long long i=0;i<n;i++){
		cin>>K[i];
		p[i].C(K[i]);
		}
	for(long long i=0;i<q;i++){
		cin>>X[i]>>Y[i];
		ans=T[X[i]]+T[Y[i]];
		
	}
	
	cout<<ans;
	return 0;
}
