#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],h,ans,f[40];
bool c[200005][40],fl;
queue<long long> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],q.push(i);
	for(int i=1;i<=n;i++){
		long long x=a[i],j=0;
		while(x>0){
			j++;
			c[i][j]=x%2;
			x=x/2;
		}
		h=max(h,j);
	}
	f[1]=1;
	for(int i=2;i<=35;i++)f[i]=f[i-1]*2;
	for(int o=h;o>=1;o--){
		int p=q.size(),num=0;
		for(int i=1;i<=p;i++){
			long long x=q.front();
			q.pop();
			if(c[x][o]==1){
				q.push(x);
				num++;
			}
		}
		
		if(num>=m){
			ans=ans+f[o];
			fl=1;
		}else{
			if(fl==0){
				while(!q.empty())q.pop();
				for(int i=1;i<=n;i++)q.push(i);
			}else break;
		}
	}
	cout<<ans;
}
