#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],v[200005],k[50],ka,mk=0,ans;
long long ksm(long long x,long long y){
	long long w=1,r=x;
	while(y){
		if(y&1) w*=r;
		r*=r;
		y>>=1;
	}
	return w;
}

long long qw(long long x,long long y){
	long long h=ksm(2,y+1);
	return (x%h)/(h>>1);
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ka=a[i];
		long long j=0;
		while(ka){
			mk=max(mk,j);
			if(ka&1==1) k[j]++;
			ka>>=1;
			j++;
		}
	}
	while(mk>=0){
		if(k[mk]<m){mk--;continue;}
		ans+=ksm(2,mk);
		for(int i=1;i<=n;i++){
			if(qw(a[i],mk)==1 || v[i]==1) continue;
			if(v[i]==0) v[i]=1;
			ka=a[i];
			int j=0;
			while(ka){
				if(ka&1==1) k[j]--;
				ka>>=1;
				j++;
			}
		}
		mk--;
	}
	cout<<ans;
	return 0;
}
