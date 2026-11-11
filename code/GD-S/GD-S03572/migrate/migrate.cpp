#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,ans[5005]={0};
ll n,d,a[5005],b[5005],vis[5005]={0};
void dfs(int ii,int jj,int f){
	int sum=0;
	for(int i=ii+1;i<=jj;i++){
		sum+=b[i];
		if(i!=jj&&sum<=d&&vis[i]!=1){
			vis[i]=1;
			dfs(i,jj,f+1);
			vis[i]=0;
		}else if(i==jj&&sum<=d&&f!=0){
			ans[f]+=1;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		t-=1;
		for(int i=1;i<=n;i++){
			ans[i]=0;
		}
		int h=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			b[i]=a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				dfs(i,j,0);
				for(int p=1;p<=n;p++){
					if(ans[p]==2){
						h+=1;
					}
				}
			}
		}
		cout<<h<<endl;
	}
	return 0;
}
