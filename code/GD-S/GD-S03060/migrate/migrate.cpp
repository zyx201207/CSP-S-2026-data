#include<bits/stdc++.h>
using namespace std;
int c,t,n,fc,f[205],h[205];
long long ans,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0,fc=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			if(x[i+1]-x[i]>d){
				f[++fc]=i;
			}
		}
		f[0]=0;
		f[++fc]=n;
		for(int a=1;a<=fc;a++){
			for(int i=f[a-1]+1;i<=f[a];i++){
				int l=f[a-1]+1,r=f[a];
				while(l<=r){
					int mid=(l+r)/2;
					if(x[mid]-x[i]<=d){
						l=mid+1;
					}
					else{
						r=mid-1;
					}
				}
				h[i]=r;
			}
		}
		for(int a=1;a<=fc;a++){
			for(int i=f[a-1]+1;i<=f[a];i++){
				for(int j=h[i]+1;j<=f[a];j++){
					int l=i,cnt1=1,sum=1;
					while(h[l]<j){
						l=h[l];
						cnt1++;
					}
					for(int k=i+1;k<h[i];k++){
						int l=i,cnt2=2;
						while(h[l]<k){
							l=h[l];
							cnt2++;
						}
						l=k;
						while(h[l]<j){
							l=h[l];
							cnt2++;
						}
						if(cnt2==cnt1){
							sum++;
						}
						if(sum>2){
							break;
						}
					}
					if(sum==2){
						ans++;
					}
				}
			}	
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
