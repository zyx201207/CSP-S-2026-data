//李杜文谦 GZ-J00407 清镇市广大实验学校
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+25;
int n,m,a[N],ma;
bool vis[N];

bool cmp(int a,int b){
	return a>b;
}

void dfs(int k,int cnt,int c){
	if(k==n+1 && c==m+1){
		ma=max(ma,cnt);
		return ;
	}
	for(int i=0;i<=1;i++){
		if(i==0)dfs(k+1,cnt,c);
		else if(i==1 &&k!=n)dfs(k+1,(cnt&a[k+1]),c+1);
	}
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,(a[i]&a[j]));
			}
		}
		cout<<ma;
		return 0;
	}else if(m==n){
		ma=a[1];
		for(int i=2;i<=n;i++)ma=(ma&a[i]);
		cout<<ma;
		return 0;
	}else if(m==n-1){
		bool flag;
		for(int i=1;i<=n;i++){
			int ans;
			for(int j=1;j<=n;j++){
				if(j!=i && flag==false){
					ans=a[j];
					flag=true;
				}else if(j!=i){
					ans=(ans&a[j]);
				}
			}
			ma=max(ans,ma);
			flag=0;
		}
		cout<<ma;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i,a[i],1);
	}
	cout<<ma;
	return 0;	
}
