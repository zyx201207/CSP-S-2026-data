#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514*2],b[114514*2][32];
struct Nove{
	int id,v;
	bool operator < (const Nove &A)const{
		return v<A.v;
	}
}vis[114514*2];
int qpow(int a,int b){
	int res=1;
	while(b>0){
		if(b&1) a*=a;
		res*=a;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
//	cout<<1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=n;i>=1;i--){
		vis[i].id=i;
		int cnt=0;
		int x=a[i];
		while(x>0){
			b[i][++cnt]=x%2;
			x/=2;
//			cout<<b[i][cnt];
		}
//		cout<< endl;
		if(i==n) sum=cnt;
	}
	for(int i=sum;i>=1;i--){
		int k=0;
		for(int j=1;j<=n;j++){
			if(b[j][i]==1){
				k++;
			}
		}
		if(k>m){
			for(int j=1;j<=n;j++){
				if(b[j][i]==1&&vis[j].v!=-1){
					vis[j].v+=qpow(2,i);
				}else if(vis[j].v==0){
					vis[j].v=-1;
				}
			}
		}else if(k==m&&i==sum){
			int ans=2147483467;
			for(int j=1;j<=n;j++){
				if(b[j][i]==1){
					ans&=a[j];
				}
			}
			cout<<ans;
			return 0;
		}
	}
	sort(vis+1,vis+n+1);
	int ans=a[vis[n].id];
	for(int i=n-1;i>=n-m+1;i--){
//		cout<<vis[i].id;
//		cout<<ans<<a[vis[i].id];I love cyq
		ans&=a[vis[i].id];
	}
	cout<<ans;
}
