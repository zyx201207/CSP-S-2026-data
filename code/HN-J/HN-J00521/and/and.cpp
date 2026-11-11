#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
#define int long long 
int b[maxn][31];
int a[maxn];
int flag[maxn];
int n,m;
bool check(int wei){
	int q=0;
	for(int i=0;i<n;i++){
		if(b[i][wei]==1&&flag[i]==0){
			q++;
		}
	}
	if(q>=m){
		return true;
	}
	else{
		return false;
	}
}
int ci(int zhi){
	int q=1;
	for(int i=1;i<=zhi;i++){
		q=q*2;
	}
	return q;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int u=-300000;
	for(int i=0;i<n;i++){
		int y=0;
		while(a[i]>0){
			int o=a[i]%2;
			b[i][y]=o;
			a[i]=a[i]/2;
			y++;
		}
		u=max(u,y);
	}
	int ans=0;
	for(int i=u;i>=0;i--){
		if(check(i)){
			for(int j=0;j<n;j++){
				if(b[j][i]==0){
					flag[j]=1;
				}
			}
			ans+=ci(i);
		}
	}
	cout<<ans<<endl;
}
