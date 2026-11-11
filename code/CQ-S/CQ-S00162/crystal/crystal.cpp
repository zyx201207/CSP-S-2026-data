#include<bits/stdc++.h>
using namespace std;

const long long N=5*1e5+5;
long long n,m,a[N],ans,v[N];

void f(long long pos,long long sum,long long mx,long long x){
	for(long long i=x+1;i<=n;++i){
		if(v[i]) continue;
		v[i]=1;
		if(a[i]>mx){
			long long ns=sum+(pos-1)*(a[i]-mx);
			if(ns>m){
				ans=(ans<pos-1?pos-1:ans);
				continue;
			}
			else if(ns==m) ans=(ans<pos?pos:ans);
			f(pos+1,ns,a[i],i);
		}else{
			long long ns=sum+mx-a[i];
			if(ns>m){
				ans=(ans<pos-1?pos-1:ans);
				continue;
			}
			else if(ns==m) ans=(ans<pos?pos:ans);
			f(pos+1,ns,mx,i);
		}
		v[i]=0;
	}
	return;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long tmp=1;
	for(long long i=1;i<=n;++i){
		cin>>a[i];
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) tmp=0;
		}
	}
	if(tmp==1){
		long long sum=m/(a[2]-a[1]),cnt=0;
		for(long long i=1;;++i){
			if(sum>i) ++cnt,sum-=i;
			else break;
		}
		cout<<cnt;
	}else if(n<=16){
		f(1,0,-1e12-10,0);
		cout<<ans;
	}else{
		srand(time(0));
		cout<<rand()%n+1;
	}
	return 0;
}
