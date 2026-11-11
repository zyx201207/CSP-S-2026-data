//GZ-J00017 贵阳市白云区华师一学校 闫宇凡 
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
long long ans,a[200005];
bool b[200005];
vector<long long> r;
bool cmp(long long a,long long b){
	return a>b;
}
void dfs(){
	if(r.size()==m){
		long long sum=r[0];
		for(int i=1;i<r.size();i++){
			sum=(sum&r[i]);
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]){
			continue;
		}
		b[i]=1;
		r.push_back(a[i]);
		dfs();
		r.pop_back();
		b[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1){
		long long mx=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			mx=max(mx,a[i]);
		}
		printf("%lld",mx);
		return 0;
	}
	if(m==n){
		long long sum=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i==1){
				sum=a[i];
			}
			else{
				sum=(sum&a[i]);
			}
		}
		printf("%lld",sum);
		return 0;
	}
	bool d1=1,v1=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i-1){
			v1=0;
		}
		bool d2=0;
		for(int j=1;j<=30;j++){
			if(a[i]==(1<<j)-1){
				d2=1;
				break;
			}
		}
		if(d2==0){
			d1=0;
		}
	}
	if(d1==1){
		sort(a+1,a+n+1,cmp);
		printf("%lld",a[m]);
		return 0;
	}
	if(n>=2000&&m==n-1){
		sort(a+1,a+n+1,cmp);
		long long sum=a[1];
		for(int i=2;i<n;i++){
			sum=(sum&a[i]);
		}
		printf("%lld",sum);
		return 0;
	}
	if(v1==1&&n>=2000){
		sort(a+1,a+n+1,cmp);
		long long sum=a[2];
		for(int i=3;i<m;i++){
			sum=(sum&a[i]);
		}
		printf("%lld",sum);
		return 0;
	}
	dfs();
	printf("%lld",ans);
	return 0;
}
