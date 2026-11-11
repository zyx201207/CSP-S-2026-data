#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,a[N],ans,p[33],c[33],sum[33][N],lastf=1;
bool cmp(int a,int b){
	return a>b;
}
void init(){
	for(int i=0;i<=30;i++){
		p[i]=pow(2,i);
	}
}
void d(int x,int id){
	for(int i=30;i>=0;i--){
		sum[i][id]=sum[i][id-1];
		if(x-p[i]>=0){
			x-=p[i];
			c[i]++;
			sum[i][id]++;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)d(a[i],i);
	for(int i=30;i>=0;i--){
		if(c[i]<m){
			continue;
		}while(true){
			if(sum[i][lastf]-sum[i][lastf-1]==1){
				break;
			}lastf++;
		}
		if(sum[i][lastf+m-1]-sum[i][lastf-1]==m){
			ans+=p[i];
		}
	} cout<<ans;
	return 0;
}
