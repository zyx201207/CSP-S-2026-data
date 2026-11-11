#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5; 
long long read(){
	long long t;
	scanf("%lld",&t);
	return t;
} 
int n;
long long m;
long long a[maxn]; 
long long sum[maxn];
queue<long long> q; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int maxn=0;
	long long s=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*i;
		if(sum[i]<=m){
			maxn=i;
			s+=a[i];
			q.push(i);
		}
		else{
			break;
		}
	}
	int p=maxn;
	while(p<=n){
		p++;
		q.push(p);
		s+=a[p];
		sum[p]=(q.size())*a[p]-s;
		while(sum[p]>m){
			sum[p]-=a[p]-a[q.front()];
			s-=a[q.front()];
			q.pop();
		}
		if(q.size()>maxn){
			maxn=q.size(); 
		}
	}
	cout<<maxn;
	return 0;
}
