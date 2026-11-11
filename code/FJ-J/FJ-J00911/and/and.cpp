#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int vs[35],b[35][200005];
int cnt[35];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=31;
	while(n>m){
		for(int i=1;i<=n;i++){
			for(int j=1;(1<<(j-1))<=a[i];j++){
				if((a[i] & (1<<(j-1)))){
					vs[j]++;
					b[j][++cnt[j]]=a[i];
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<i<<"   ";
//			for(int j=1;j<=cnt[i];j++){
//				cout<<b[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		bool bb=1;
		for(int i=sum-1;i>=0;i--){
			if(vs[i]>=m){
				bb=0;
				n=cnt[i];
				sum=i;
				for(int j=1;j<=cnt[i];j++){
					a[j]=b[i][j];
				}
				break;
			}
		}
		if(bb==1){
			break;
		}
		memset(vs,0,sizeof vs);
		memset(b,0,sizeof b);
		memset(cnt,0,sizeof cnt);
	}
	int ans=a[1];
	for(int i=1;i<=n;i++){
		ans=ans&a[i];
	}
	cout<<ans<<endl;;
	return 0;
}

