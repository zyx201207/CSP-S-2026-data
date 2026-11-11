#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	long long v[200010];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	int last=n;
	long long ans=0;
	for(int k=29;k>=0;k--){
		int cnt=0;
		long long w[200010];
		for(int i=1;i<=last;i++){
			if((v[i]>>k)&1==1){
				cnt++;
				w[cnt]=v[i];
			}
		} 
		if(cnt>=m){
			ans+=1<<k;
			last=cnt;
			for(int i=1;i<=cnt;i++)v[i]=w[i];
		}
	}
	cout<<ans;
	return 0;
} 
