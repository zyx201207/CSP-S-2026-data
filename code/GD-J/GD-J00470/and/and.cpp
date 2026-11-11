#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+21;
int n,m;
int maxn,sum;
int a[N];
int b[N];
int len;
void cut(int x){
	int ji=0;
	while(x){
		ji++;
		b[ji]++;
		x/=2;
	}
	len=max(len,ji);
}
int popc(int x){
	int ji=0;
	while(x){
		ji+=x%2;
		x/=2;
	}
	return ji;
}
int popc2(int x){
	int ji=0,su=0;
	while(x){
		ji++;
		if(x&1){
			if(!su)su=a[ji];
			else su=su&a[ji];
		}
		x/=2;
	}
	return su;
}
int check1(){
	for(int i=1;i<=n;i++){
		if(log2(a[i]+1)!=popc(a[i]))return 0;
	}
	return 1;
}
int check2(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1)return 0;
	}
	return 1;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cut(a[i]);
		maxn=max(maxn,a[i]);
		if(i==1)sum=a[1];
		else sum&=a[i];
	}
	if(m==1){
		cout<<maxn;
	}else if(m==n){
		cout<<sum;
	}else if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}else if(m==n-1){
		int ji=0;
		for(int i=1;i<=n;i++){
			int s;
			for(int k=len;k>=1;k--){
				if(b[k]==n-1&&((a[i]&(1<<(k-1)))==0)){
					s+=(1<<(k-1));
				}
			}
			ji=max(ji,s);
		}
		cout<<sum+ji;
	}else if(check1()){
		for(int i=len;i>=1;i--){
			if(b[i]>=m){
				cout<<(1<<i)-1;
				break;
			}
		}
	}else if(check2()){
		cout<<(a[n]&a[n-m+1]);
	}else{
		int ans=0;
		for(int i=0;i<=(1<<n)-1;i++){
			if(popc(i)==m){
				ans=max(ans,popc2(i));
			}
		}
		cout<<ans;
	}
}
