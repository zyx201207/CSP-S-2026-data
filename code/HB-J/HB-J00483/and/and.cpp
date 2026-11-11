#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long and_solve(int a,int b){
	int x[1000]={0},y[1000]={0},c[1000]={0},idxx=0,idxy=0,last=0;
	long long num=0;
	while(a){
		x[++idxx]=a%2;
		a/=2;
	}
	while(b){
		y[++idxy]=b%2;
		b/=2;
	}
	for(int i=1;i<=max(idxx,idxy);i++){
		if(x[i]==1&&y[i]==1){
			c[i]=1;
			last=i;
		}
	}
	int ji=1;
	for(int i=1;i<=last;i++){
		num+=ji*c[i];
		ji*=2;
	}
	return num;
}
int n,m;
long long shu[N]={0};
int main(void){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long ma=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>shu[i];
		ma=max(shu[i],ma);
	}
	
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		int ans=shu[1];
		for(int i=2;i<=n;i++){
			ans=and_solve(ans,shu[i]);
		}
		cout<<ans;
		return 0;
	}
	if(n>2000){
		cout<<ma-1;
		return 0;
	}
	if(m==2){
		long long ans=INT_MIN;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,and_solve(shu[i],shu[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==3){
		long long ans=INT_MIN;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,and_solve(shu[k],and_solve(shu[i],shu[j])));
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==4){
		long long ans=INT_MIN;
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int x=j+1;x<=n-1;x++){
					for(int y=x+1;y<=n;y++){
						ans=max(ans,and_solve(and_solve(shu[x],shu[y]),and_solve(shu[i],shu[j])));
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==5){
		long long ans=INT_MIN;
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int x=j+1;x<=n-2;x++){
					for(int y=x+1;y<=n-1;y++){
						for(int k=y+1;k<=n;k++){
							ans=max(ans,and_solve(shu[k],and_solve(and_solve(shu[x],shu[y]),and_solve(shu[i],shu[j]))));
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
