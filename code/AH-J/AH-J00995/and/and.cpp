#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
void work1(){
	long long mx=0;
	for(int i=0;i<(1<<n);i++){
		long long res=-1;
		int ret=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				ret++;
				if(res==-1){
					res=a[j+1];
				}else{
					res=(res&a[j+1]);
				}
			}
		}
		if(ret==m){
			mx=max(mx,res);
		}
	}
	cout<<mx;
	return;
}
long long pre[N],nxt[N];
inline long long lowbit(long long x){
	return x&(-x);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool f1=1,f2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)f1=0;
		if(a[i]>=4)f2=0;
	}
	if(m==1){
		long long mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}if(m==2 && n<=2000){
		long long mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
		return 0;
	}if(n<=20){
		work1();
		return 0;
	}if(m==n-1){
		pre[1]=a[1];
		for(int i=2;i<n;i++){
			pre[i]=(pre[i-1]&a[i]);
		}
		nxt[n]=a[n];
		for(int i=n-1;i>=2;i--){
			nxt[i]=(nxt[i+1]&a[i]);
		}
		long long mx=max(pre[n-1],nxt[2]);
		for(int i=2;i<n;i++){
			mx=max(mx,(pre[i-1]&nxt[i+1]));
		}
		cout<<mx;
		return 0;
	}if(f1){
		long long ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}if(f2){
		int cnt[5]={0};
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		if(cnt[3]>=m){
			cout<<3;
		}else if(cnt[3]+cnt[2]>=m){
			cout<<2;
		}else if(cnt[3]+cnt[2]+cnt[1]>=m){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	bool f=1;
	for(int i=1;i<=n;i++){
		long long k=a[i]+1;
		long long k2=lowbit(k);
		if(k-k2!=0){
			f=0;
			break;
		}
	}
	if(f){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
	return 0;
}

