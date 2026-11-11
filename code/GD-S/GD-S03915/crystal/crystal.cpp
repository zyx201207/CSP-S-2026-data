#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) sum[i]=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int cnt=m;
		int p=0;
		if(i==1){
			for(int j=2;j<=n;j++){
				if(cnt-(a[j]-a[1])>=0){
					cnt-=(a[j]-a[1]);
					sum[1]++;;
				}else{
					p=1;
				}
			}
		}else if(i==n){
			for(int j=n-1;j>=1;j--){
				if(cnt-(a[n]-a[j])>=0){
					cnt-=(a[n]-a[j]);
					sum[n]++;
				}else{
					p=2;
				}
			}
		}
		if(p==1)continue;
		else if(p==2)break;
		int x=i-1,y=i+1;
		int u=0;
		while(u<2){
			if((a[i]-a[x])<(a[y]-a[i])){
				if(cnt-(a[i]-a[x])>=0&&x!=-1){
					cnt-=(a[i]-a[x]);
					sum[i]++;
					if(x==1){
						u++;
						x==-1;
					}else{
						x-=1;
					}
				}else{
					u++;
				}
			}else{
				if(cnt-(a[y]-a[i])>=0&&y!=-1){
					cnt-=(a[y]-a[i]);
					sum[i]++;
					if(y==n){
						u++;
						y=-1;
					}else{
						y+=1;
					}
				}else{
					u++;
				}
			}
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,sum[i]);
	}
	cout<<maxn;
	return 0;
}
