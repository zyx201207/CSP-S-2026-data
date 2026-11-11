#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N][40],x[N],y,num,now,ans;
bool vis[N];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	sort(x+1,x+1+n,cmp);
	for(int i=1;i<=n;i++){
		y=30;
		while(x[i]){
			a[i][y]=x[i]%2;
			x[i]/=2;
			y--;
		}
	}
	now=pow(2,30);
	for(int i=0;i<=30;i++){
		num=0;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&a[j][i]==1)
				num++;
		if(num>=m){
			for(int j=1;j<=n;j++)
				if(!a[j][i])
					vis[j]=1;
			ans+=now;
		}
		now/=2;
	}
	cout<<ans;
	return 0;
}

