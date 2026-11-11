#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[1000001],t[1000001],s1,s2=1,s3,ans,er[10001],dis[1000001],vis[1000001],hhh[1000001];
void init(){
	er[0]=1;
	for(int i=1;i<=61;i++){
		er[i]=2*er[i-1];
	}
}
void aaa(int q,int k,int u){
	if(k==m){
		ans=max(ans,u);
		return ;
	} 
	if(q>n) return ;
	aaa(q+1,k+1,u&a[q]);
	aaa(q+1,k,u);	
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	init();
	cin>>n>>m;
	if(m==0) cout<<0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		double k;
		k=log2(a[i]+1);
		if(k!=(int)k) s2=0;
		s3=max(s3,a[i]);
	}
	if(n<=20){
		aaa(1,0,er[60]-1);
		cout<<ans;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(m==n){
		ans=er[60]-1;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==n-1){
		ans=er[60]-1;
		dis[0]=er[60]-1;
		vis[n+1]=er[60]-1;
		for(int i=1;i<=n;i++){
			ans&=a[i];
			dis[i]=ans;
		}
		ans=er[60]-1;
		for(int i=n;i>=1;i--){
			ans&=a[i];
			vis[i]=ans;
		}
//		s1=ans;
		ans=0;
		for(int i=1;i<=n;i++){
//			cout<<
			ans=max(ans,dis[i-1]&vis[i+1]);
		} 
		cout<<ans;
	}
//	else if(m==n-2){ 
//		ans=er[60]-1;
//		for(int i=1;i<=n;i++){
//			ans|=a[i];
//		}
//		s1=ans;
//		ans=0;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(j==i) continue;
//				ans=max(ans,s1|a[i]|a[j]);
//			}
//		} 
//		cout<<ans;
//	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(s2){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	else if(s3<=4){
		for(int i=1;i<=n;i++){
			hhh[a[i]]++;
		}
		if(hhh[4]>=m) cout<<4;
		else if(hhh[3]>=m) cout<<3;
		else if(hhh[3]+hhh[2]>=m) cout<<2;
		else if(hhh[3]+hhh[1]>=m) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
