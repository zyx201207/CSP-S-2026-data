#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int a[200005],c[200005];
int b[200005][35];
int js[200005];
int maxn;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			int t=a[i],cnt=0;
			while(t!=0){
				int x=t%2;
				t=t/2;
				cnt++;
				c[cnt]=x;
				js[i]++;
			}
			for(int j=cnt;j>=1;j--){
				b[i][j]=c[cnt-j+1];
			}
		}
		int ans[35];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int z=0;
				if(js[i]>=js[j]){
					for(int k=1;k<=js[j];k++){
						if(b[i][js[i]-js[j]+k]==1&&b[j][k]==1){
							
							ans[k]=1;
						} 
						else ans[k]=0;
					}
					for(int k=js[j];k>=1;k--){
						int tt=js[j]-k,cd=1;
						for(int r=1;r<=tt;r++) cd*=2;
						z+=ans[k]*cd;
					}
				}
				else{
					for(int k=1;k<=js[i];k++){
						if(b[j][js[j]-js[i]+k]==1&&b[i][k]==1){
							ans[k]=1;
						} 
						else ans[k]=0;
					}
					for(int k=js[i];k>=1;k--){
						int tt=js[i]-k,cd=1;
						for(int r=1;r<=tt;r++) cd*=2;
						z+=ans[k]*cd;
					}
				}
				maxn=max(maxn,z);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			int t=a[i],cnt=0;
			while(t!=0){
				int x=t%2;
				t=t/2;
				cnt++;
				c[cnt]=x;
				js[i]++;
			}
			for(int j=cnt;j>=1;j--){
				b[i][j]=c[cnt-j+1];
			}
		}
		int ans[35];
		int i=1;
		int z=0;
		for(int j=2;j<=n;j++){
			z=0;
			if(js[i]>=js[j]){
				for(int k=1;k<=js[j];k++){
					if(b[i][js[i]-js[j]+k]==1&&b[j][k]==1){
						
						ans[k]=1;
					} 
					else ans[k]=0;
				}
				for(int k=js[j];k>=1;k--){
					int tt=js[j]-k,cd=1;
					for(int r=1;r<=tt;r++) cd*=2;
					z+=ans[k]*cd;
				}
			}
			else{
				for(int k=1;k<=js[i];k++){
					if(b[j][js[j]-js[i]+k]==1&&b[i][k]==1){
						ans[k]=1;
					} 
					else ans[k]=0;
				}
				for(int k=js[i];k>=1;k--){
					int tt=js[i]-k,cd=1;
					for(int r=1;r<=tt;r++) cd*=2;
					z+=ans[k]*cd;
				}
			}
			i=z;
		}
		cout<<z;
		return 0;
	}
	return 0;
}
/*
4 2
3 15 12 12
*/
