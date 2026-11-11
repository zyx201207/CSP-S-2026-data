#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pair;
const int N=2e6+5;
int n,dis[N];
ll a[N];
int l[N];
ll d;
int fang[N];
int f[N];
void mian(){
	cin>>n>>d;
	ll ans=0;
	for(int i=1,j=1;i<=n;i++){
		cin>>a[i];
		while(a[j]+d<a[i]) j++;
		l[i]=j;
	}
	for(int i=1;i<=n;i++){
		dis[i]=0;
		fang[i]=1;
		f[0]=1;
		int j,k;
		for(j=i+1,k=i;j<=n;j++){
			while(k<l[j]){
				f[dis[k]]-=fang[k];
				k++;
			//	cout<<"e:"<<k<<endl;
			}
			if(l[j]==j) break;
			dis[j]=dis[l[j]]+1;
			fang[j]=f[dis[l[j]]];
			fang[j]=min(fang[j],3);
			if(f[dis[l[j]]]==2) ans++;
			f[dis[j]]+=fang[j];
		//	cout<<j<<" "<<l[j]<<":"<<dis[j]<<" "<<fang[j]<<" - "<<ans<<endl;
		}
		while(k<=n) f[dis[k++]]=0;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--){
		mian();
	}
	return 0;
}
/*
华夏风韵，洛水天依 
*/ 
