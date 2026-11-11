#include<bits/stdc++.h>
using namespace std;
int a[200050],n,m;
long long ans=0;
void dfs(int z,int x,long long y){
	if(z==m+1){
		ans=max(ans,y);
		return ;
	}
	if(x==n+1) return ;
	long long d=y;
	if(z==1){
		y=a[x];
	}
	else y&=a[x];
	dfs(z+1,x+1,y);
	y=d;
	dfs(z,x+1,y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,1,0);
		cout<<ans;
	}
	else{
		if(m==1){
			for(int i=1;i<=n;i++){
				if(a[i]>ans) ans=a[i];
			}
			cout<<ans;
		}
		else{
			if(m==n){
				for(int i=1;i<=n;i++){
					if(i==1) ans=a[i];
					else ans&=a[i];
				}
				cout<<ans;
			}
			else{
				if(m==2){
					for(int i=1;i<=n;i++){
						for(int j=1;j<=n&&i!=j;j++){
							long long s=a[i]&a[j];
							ans=max(ans,s);
						}
					}
					cout<<ans;
				}
				else{
					long long s=0,r=1;
					for(int i=1;i<=n;i++){
						if(a[i]%n>=m) s++;
					}
					if(s<m){
						for(int i=1;i<=n;i++){
							if(a[i]%n<m&&r!=m+1){
								if(r==1){
									ans=a[i];
								}
								else{
									ans&=a[i];
								}
								r++;
							}
						}
					}
					else{
						for(int i=1;i<=n;i++){
							if(a[i]%n>=m&&r!=m+1){
								if(r==1){
									ans=a[i];
								}
								else{
									ans&=a[i];
								}
								r++;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
