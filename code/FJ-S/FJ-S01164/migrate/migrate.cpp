#include<bits/stdc++.h>
using namespace std;
long long arr[5005];
int c,t,n,m,ans;
int ne[5005][2];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==12||c==11){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				scanf("%lld",arr+i);
			}
			for(int j=1;j<=n;j++){
				if(arr[1]<arr[j]-m){
					break;
				}
				ne[1][1]=j;
			}
			int k=ne[1][1];
			k=k*2-1;
			cout<<n-k+1;
		}
	}
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			scanf("%lld",arr+i);
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--){
				if(arr[i]>arr[j]+m){
					break;
				}
				ne[i][0]=j;
			}
			for(int j=i;j<=n;j++){
				if(arr[i]<arr[j]-m){
					break;
				}
				ne[i][1]=j;
			}
//			cout<<ne[i][0]<<" "<<ne[i][1]<<"\n";
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<j-1;k++){
					if(ne[i][1]==k+1&&ne[j][0]==k){
						ans++;
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
