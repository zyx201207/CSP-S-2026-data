#include <bits/stdc++.h>
using namespace std;
const long long MAXN=2e6;
long long a[MAXN];
struct node{
	long long idx,step;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,T;
	cin>>c>>T;
	while(T--){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		while(a[n]-a[n-1]>d) n--;
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				queue<node> q;
				q.push({i,0});
				long long cnt=0,mi=9e18;
//				long long cntttttt=0;
				while(!q.empty()){
					
//					cout<<"In range "<<i<<" "<<j<<" "<<++cntttttt<<"\n";
//					queue<node> q1=q;
//					while(!q1.empty()){
//						cout<<q1.front().idx<<" "<<q1.front().step<<"\n";
//						q1.pop();
//					}
					
					long long idx=q.front().idx,step=q.front().step;q.pop();
//					cout<<idx<<" "<<step<<"\n";
					if(step>mi) continue;
					if(idx>j) continue;
					if(idx==j){
//						cout<<idx<<" "<<step<<"\n";
						if(mi==1e9){
							mi=step;
							cnt=1;
						}else{
							if(step<mi){
								mi=step;
								cnt=1;
							}else if(step==mi){
								cnt++;
							}
						}
					}
					for(long long k=idx;k<=j;k++){
//						if(i==1&&j==4) cout<<k<<" "<<idx<<" "<<a[k]-a[idx]<<"\n";
						if(a[k]-a[idx]>d) break;
						q.push({k,step+1});
					}
				}
				if(cnt==2){
//					cout<<i<<" "<<j<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
