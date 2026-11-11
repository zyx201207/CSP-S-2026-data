#include<bits/stdc++.h> 
using namespace std;
long long n,m,t[200005],a[200005],j,cnt[200005][35],sum[35],maxn=0;
void dg(int x){
	if(x==0){
		return ;
	}
	if(sum[x]<m){
		dg(x-1);
		return ;
	}
	int te=j;
	j=0;
	for(int i=1;i<=te;i++){
		if(cnt[t[i]][x]==1){
			j++;
			t[j]=t[i];
		}
	}
	sum[x-1]=0;
	for(int i=1;i<=te;i++){
		sum[x-1]+=cnt[t[i]][x-1];
	}
	dg(x-1);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=i;
		long long tem=a[i];
		bool f=1;
		for(int j=30;j>=0;j--){
			if(tem>(1<<j)){
				cnt[i][j]++;
				tem-=(1<<j);
				if(f){
					maxn=max(maxn,j);
					f=0;
				}
			}
			if(tem==0){
				break;
			}
		}
		for(int j=0;j<=31;j++){
			sum[j]+=cnt[i][j];
		}
	}
	j=n;
	dg(30);
	long long ans=a[t[1]];
	for(int i=2;i<=j;i++){
		ans&=a[t[i]];
	}
	cout<<ans;
	return 0;
}

