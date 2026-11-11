#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200200],b[10];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1){
			res=res*a;
		}
		a=a*a;
		b/=2;
	}
	return res;
}
bool check(){
	for(int i=1;i<=n;i++){
		int x=floor(log2(a[i]+1));
		if(qpow(2,x)-1!=a[i]){
			return 0;
		}
	}
	return 1;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=20){
		int nn=qpow(2,n)-1,ans=0;
		for(int i=1;i<=nn;i++){
			int cnt=0,sum=0;
			bool f=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					cnt++;
					if(!f){
						sum=a[j];
						f=1;
					}else{
						sum&=a[j];
					}
				}
			}
			if(cnt==m){
				ans=max(ans,sum);
			}
		}
		cout<<ans;
	}else if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(n<=2000&&m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(maxx<4){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		if(b[3]>=m){
			cout<<3;
		}else if(b[2]+b[3]>=m){
			cout<<2;
		}else if(b[1]+b[3]>=m){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(qpow(2,floor(log2(n)))==n){
		int x=log2(n),ans=0;
		for(int i=1;i<=x;i++){
			if(m>n/qpow(2,i)){
				cout<<ans;
				return 0;
			}
			ans+=qpow(2,x-i);
		}
		cout<<ans;
	}else if(check()){
		for(int i=1;i<=n;i++){
			a[i]=log2(a[i]+1);
		}
		sort(a+1,a+n+1);
		cout<<qpow(2,a[n-m+1])-1;
	}else{
		cout<<0;
	}
	return 0;
} 
