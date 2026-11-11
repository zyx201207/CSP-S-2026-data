#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,m,num,a[1001010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		num=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int l=1;l<=n;l++){
			for(int r=l+2;r<=n;r++){
				__int128 sum=0,k=0;
				int p=1,p2=0;
				for(int i=l+1;i<=r;i++){
					sum+=a[i]-a[i-1];
					if(sum>m){
						p++;
						sum=a[i]-a[i-1];
						if(sum>m){
							k=1;
							break;
						}
					}
					if(p==1)p2=i;
				}	
				if(k==1)continue;
				sum=0,k=0;
				int p3=2;
				for(int i=p2;i<=r;i++){
					sum+=a[i]-a[i-1];
					if(sum>m){
						p3++;
						sum=a[i]-a[i-1];
						if(sum>m){
							k=1;
							break;
						}
					}
				}
				if(p3!=p)continue;
				if(r==l+2){
					num++;
					continue;
				}
				int p4=2;
				sum=0,k=0;
				for(int i=p2-1;i<=r;i++){
					sum+=a[i]-a[i-1];
					if(sum>m){
						p4++;
						sum=a[i]-a[i-1];
						if(sum>m){
							k=1;
							break; 
						}
					}
				}
				if(p4!=p)num++;
			}
		}
		cout<<num<<"\n";
	}
	return 0;
}
