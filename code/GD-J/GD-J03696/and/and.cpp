#include<bits/stdc++.h>
using namespace std;
//long long !!!!!!!!!
long long n,m,a[200005],cnt[35],ans=0,ng[200005][4],z=0,ts,t;
void clec(){
	for(int i=0;i<=30;i++) cnt[i]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>m;
	t=n;
	long long maxn=0;
	int maxi=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ng[i][0]=a[i];
		maxn=max(maxn,a[i]);
		for(int j=0;(1<<j)<=maxn;j++){
			cnt[j]+=(((1<<j)&a[i])>>j);
			maxi=max(maxi,j);
		}
	}
	int k=maxi;
	while(k>=0){
		while(k>=0&&cnt[k]<m){
			k--;
		}
		//cout<<k<<"\n";
		if(k<0){
			break;
		}
		ans=(ans|(1<<k));
		clec();
		bool flag=1;
		ts=0;
		for(int i=1;i<=t;i++){
			if(ng[i][z]&(1<<k)){
				//cout<<ng[i][z]<<"   test\n";
				ng[++ts][1-z]=ng[i][z];
				for(int j=0;j<k;j++){
					cnt[j]+=((ng[ts][1-z]&(1<<j))>>j);
					if(cnt[j]>=m) flag=0;
					//cout<<cnt[j]<<" ";
				}
				//cout<<"\n";
			}
		}
		if(flag){
			break;
		}
		t=ts;
		z=1-z;
		k--;
	}
	/*
4 2
3 15 12 12

	*/
	cout<<ans;
} 
