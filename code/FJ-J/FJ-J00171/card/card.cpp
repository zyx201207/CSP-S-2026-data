#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d[500005],ans[300005];
bool a[300005],b[300005];
deque<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
	for(int i=1;i<n;i++){
		if(i==1||b[d[i-1]]){
			for(int j=1;j<=m;j++) a[j]=b[j]=0;
			q.clear();
			for(int j=i;j<=n;j++){
//				cout<<j<<'\n';
				if(a[d[j]]){
					b[d[j]]=1;
					while(q.back()!=d[j]){
						a[q.back()]=0;
						q.pop_back();
					}
				}
				else{
					q.push_back(d[j]);
					a[d[j]]=1;
				}
			}
		}
		else if(d[i]==q[1]){
			a[d[i-1]]=0;
			q.pop_front();
		}
		for(int j=1;j<=m;j++) ans[j]+=a[j];
//		for(int j=1;j<=m;j++) cout<<ans[j]<<" ";
//		cout<<"\n";
	}
	ans[d[n]]++;
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
//T4
//100+80+80+60=320
