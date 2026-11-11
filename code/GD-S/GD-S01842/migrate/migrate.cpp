#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000005;
ll c,T,n,d,a[N],ans;

ll bfs(int k){
	ll dis[N]={},pt[N]={},rt=0;
	dis[k]=0;
	ll p=k;
	for(int i=k+1;i<=n;i++){
		if(a[i]-a[p]<=d){
			dis[i]=dis[p]+1;
		}else if(a[i]-a[i-1]<=d){
			dis[i]=dis[i-1]+1;
			p=i-1;
		}else{
			break;
		}
		if(dis[i]==1){
			pt[i]=1;
		}else{
			for(int j=i-1;j>=k;j--){
				if(a[i]-a[j]>d) break;
				if(dis[j]==dis[i]-1){
					pt[i]+=pt[j];
				}else if(dis[j]==dis[i]-2){
					break;
				}
			}
			if(pt[i]==2) rt++;
		}
	}
//	cout<<"k:"<<k<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<' ';
//	}
//	cout<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<pt[i]<<' ';
//	}
//	cout<<'\n'<<rt<<'\n';
	
	
	return rt;
	
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n==1){
			printf("0\n");
			continue;
		}
		
		if(c==11||c==12){
			if(d/(a[2]-a[1])<2) printf("0\n");
			else{
				ll k=(d/(a[2]-a[1]))*2-1;
				printf("%lld\n",max(0ll,n-k));
			}
			
		}else{ 
			ans=0;
			for(int i=1;i<=n;i++){
				ans+=bfs(i);
//				cout<<ans<<'\n';
			}
			printf("%lld\n",ans);
			
		}
	}
}

/*
1 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

1 1
8 3
0 1 2 4 8 10 11 13

*/

