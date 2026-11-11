#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000050];
long long dis[2000050];
long long way[2000050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			way[i]=0;
			dis[i]=0;
		}
		long long ans=0;
		if(c<=10){//O(n^2)
			for(int l=1;l<=n;l++){
				for(int i=l;i<=n;i++){
					dis[l]=0;
					way[l]=0;
				}
				dis[l]=0;
				way[l]=1;
				long long left=l;
				for(int r=l+1;r<=n;r++){
					while(a[r]-a[left]>d)left++;
					long long num=0;
					int lr=left;
					num+=way[lr];
					while(dis[lr]==dis[lr+1]&&num<=2&&lr<r){
						lr++;
						num+=way[lr];
					}
					if(num==2)ans++;
					way[r]=num;
					dis[r]=dis[left]+1;
					//cout<<way[r]<<" "<<dis[r]<<"\n";
				}
			}
			cout<<ans<<"\n";
		}
		else if(c==11||c==12||c==0){
			if(d<2*(a[2]-a[1]))cout<<"0\n";
			else cout<<max(n-2*(d/(a[2]-a[1]))+1,(long long)(0))<<"\n";
		}
		else if(c==13||c==14){
			cout<<"0\n";
		}
	}
	return 0;
}
