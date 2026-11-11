#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],maxn;
bool b[200009][40];
map<long long,long long>Log;
long long lowbit(long long x){
	return x&(-x);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(long long i=0,x=1;i<=40;i++,x*=2){
		Log[x]=i;
	}
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		long long x=a[i];
		maxn=max(maxn,x);
		while(x){
			long long lbit=lowbit(x);
			b[i][Log[lbit]]=1;
			x-=lbit;
		}
	}
	if(maxn>2*2*2*2*2*2*2*2*2*2){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	for(long long i=maxn;i>0;i--){
		long long sum=0;
		for(long long j=1;j<=n;j++){
			bool flag=1;
			long long x=i;
			while(x){
				long long lbit=lowbit(x);
				if(!b[j][Log[lbit]]){
					flag=0;
					break;
				}
				x-=lbit;
			}
			if(flag){
				sum++;
				if(sum>=m){
					cout<<i;
					return 0;
				}
			}
		}
	}
	cout<<0;
	return 0;
}

