#include<bits/stdc++.h>
using namespace std;
long long n,m,a[212345],ans;
void f(long long x,long long cnt,long long num){
	if(cnt==m){
		ans=max(ans,num);
		return;
	} 
	for(long long i=x+1;i<=n;i++) f(i,cnt+1,num&a[i]); 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		long long maxn=0;
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
	}
	else if(m==n){
		long long num=a[1];
		for(int i=2;i<=n;i++) num&=a[i];
		cout<<num;
	}
	else if(m==2){
		long long maxn=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				long long num=a[i]&a[j];
				maxn=max(maxn,num);
			}
		}
		cout<<maxn;
	}
	else if(n<=20){
		for(int i=1;i<=n;i++) f(i,1,a[i]); 
		cout<<ans;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			long long num=a[1];
			if(i==1) num=a[2];
			for(int j=2;j<=n;j++){
				if(i!=j) num&=a[i];
			} 
			cout<<num;
		}
	}
	else cout<<0;
	return 0;
} 
