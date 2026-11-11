#include<bits/stdc++.h>
using namespace std;
long long ans[300005];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	long long a[500005];
	cin>>n>>m;
	for(long long i=1;i<=n;++i){
		cin>>a[i];
	}
	long long q[500005],ind[300005];
	for(long long i=1;i<=n;++i){
		long long l=1,r=0;	
		memset(q,0,sizeof(q));
		memset(ind,0,sizeof(ind));
		for(long long j=i;j<=n;++j){
			q[r+1]=a[j];
			r++;
			if(ind[a[j]]!=0){
				r--;
				while(r>ind[a[j]]){
					ind[q[r]]=0;
					r--;
				}
				continue;
			}
			ind[a[j]]=r;
		}
		for(long long j=1;j<=m;++j){
			if(ind[j]){
				ans[j]++;
			}
		}
	}
	for(long long i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
