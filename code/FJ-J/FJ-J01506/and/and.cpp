#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
struct node{
	long long q,b;
}a[200005];
long long f(long long k){
	int ans=0;
	while(k){
		if(k&1)ans++;
		k/=2;
	}
	return ans;
}
bool cmp(node x,node y){
	return x.b>y.b;
}
bool cmpp(node x,node y){
	return x.q>y.q;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i].q;
		a[i].b=f(a[i].q);
	}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1].q;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			cnt=(cnt&a[i].q);
		}
		cout<<cnt;
		return 0;
	}
	if(m==2){
		long long maxn=0; 
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i].q&a[j].q));
				//cout<<(a[i].q&a[j].q);
			}
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cnt=a[1].q;
	for(long long i=2;i<=m;i++){
		if(cnt&a[i].q){
			cnt=(cnt&a[i].q);
		}else{
			m+=1;
		}
	}
	cout<<cnt;
	return 0;
}
