#include<bits/stdc++.h>
using namespace std;
int a[2050];
int s1[5000];
int s2[5000];
int s3[5000];
long long ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long maxm=0;
	int maxn=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0;
				int f=1;
				int u=1;
				int o=1;
				int g=a[i];
				int ff=a[j];
				while(1){
					if(g==0){
						break;
					}
					int x=g%2;
					s1[f]=x;
					g/=2;
					f++;
				}
				while(1){
					if(ff==0){
						break;
					}
					int y=ff%2;
					s2[u]=y;
					ff/=2;
					u++;
				}
				for(int k=1;k<=max(f,u);k++){
					if(s1[k]==0 || s2[k]==0){
						s3[o]=0;
					}else{
						s3[o]=1;
					}
					o++;
				}
				for(int p=o;p>=1;p--){
					ans+=s3[p]*pow(2,p);
					
				};
				maxm=max(ans/2,maxm);
			}
		}
	
	cout<<maxm;
	return 0;
}
