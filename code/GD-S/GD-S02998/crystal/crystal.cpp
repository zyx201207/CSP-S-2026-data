#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500003],nxt[500003],dist[500003],sum[500003];
bool A=1,B=1;

void uniqueA(){
	long long ans;
	for(ans=1;ans<=n&&(ans-1)*ans/2<=m;ans++){}
	cout<<ans-1;
	return;
}

void uniqueB(){
	if(n==1){
		cout<<1;
		return;
	}
	long long ans,X=a[2]-a[1];
	for(ans=1;ans<=n&&(ans-1)*ans/2*X<=m;ans++){}
	cout<<ans-1;
	return;
}

void solve(){
	sort(a+1,a+n+1);
	nxt[n]=dist[n]=sum[n]=sum[n+1]=0;
	for(int i=1;i<n;i++){
		nxt[i]=a[i+1]-a[i];
	}
	for(int i=n-1;i>=1;i--){
		dist[i]=dist[i+1]+nxt[i];
		sum[i]=sum[i+1]+dist[i];
	}
	
//	for(int i=1;i<=n;i++)cout<<sum[i]<<" ";
//	第l至第r小的宝石全部转为第(r+1)小宝石所需:(sum[l]-sum[r+1])-dist[r+1]*(r-l+1)
	for(int len=n-1;len>=0;len--){
		for(int k=n;k>=len+1;k--){
			int l=k-len,r=k-1;
			if( (sum[l]-sum[r+1])-dist[k]*(r-l+1) <= m ){
				cout<<len+1;
				return;
			}
		} 
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 

	cin>>n>>m;
	cin>>a[1];
	A=A&&(a[1]==1);
	for(int i=2;i<=n;i++){
		cin>>a[i];
		A=A&&(a[i]==i);
		B=B&&(a[i]-a[i-1]==a[2]-a[1]);
	}
	
//	cout<<A<<" "<<B<<"\n";
	if(A)uniqueA();
	else if(B)uniqueB();
	else solve();
	
	return 0;
} 
