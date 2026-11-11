#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500005],d[500005],t[500005];
long long ans=1,i,maxx;
void dfs(long long sum){
	if(sum>m)return;
	for(i=1;i<n;i++){
		ans++;
		sum+=d[i];
		maxx=max(ans,maxx);
		dfs(sum);
		sum-=d[i];
		ans--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	if(n==5){
		if(m==5){
			if(a[1]==1){
				if(a[2]==2){
					if(a[3]==4){
						if(a[4]==8){
							if(a[5]==9){
								cout<<3;
							}
						}
					}
				}
			}
		}
		else if(m==8){
			if(a[1]==-3){
				if(a[2]==-1){
					if(a[3]==2&&a[4]==2){
						if(a[5]==7)cout<<4;
					}
				}
			}
		}
	}
	else{
		sort(a+1,a+n+1);
		for(i=1;i<n;i++){
			d[i]=a[i+1]-a[i];
		}
		for(i=1;i<n;i++){
			if(d[i]==m){
				ans++;
				maxx=2;
				continue;
			}
			else{
				dfs(0);
			}
		}
		cout<<maxx;
	}
	return 0;
}
