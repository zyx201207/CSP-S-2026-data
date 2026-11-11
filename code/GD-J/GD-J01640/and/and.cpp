#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],l[N],r[N],ans,k;
void solve1(){
	for(int i=0;i<(1<<n);i++){
		int c=0,res;
		for(int j=1;j<=n;j++){
			if(1&(i>>(j-1))){
				if(c==0)res=a[j];
				else res&=a[j];
				c++;
			}
		}
		if(c==m)
		ans=max(ans,res);
	}
	cout<<ans;
	return ;
}
void solve2(){
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}else if(m==n){
		int res=a[1];
		for(int i=1;i<=n;i++)res&=a[i];
		cout<<res;
	}
	return ;
}
void solve3(){
	if(m==n-1){
		l[1]=a[1];
		r[n]=a[n];
		for(int i=2;i<=n;i++){
			l[i]=a[i]&l[i-1];
		}
		for(int i=n-1;i>=1;i--){
			r[i]=a[i]&r[i+1];
		}
		int maxn=max(r[2],l[n-1]);
		for(int i=2;i<n;i++){
			maxn=max(l[i-1]&r[i+1],maxn);
		}
		cout<<maxn;
	}else{
		sort(a+1,a+n+1,greater<int>());
		int maxn=a[1];
		for(int i=1;i<=m;i++){
			maxn&=a[i];
		}
		cout<<maxn;
	}
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		solve1();
	}else if(n<=2000){
		solve2();
	}else {
		solve3();
	} 
	return 0;
}
