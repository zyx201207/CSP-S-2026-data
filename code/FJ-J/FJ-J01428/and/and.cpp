#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0x3f3f3f3f,a[200005];
int lobit(int x){
	return x&-x;
}
int tj(int a){
	int oi=0;
	while(a!=0){
		oi++;
		a-=lobit(a);
	}
	return oi;
}
bool cmp(int a,int b){
	return tj(a)>tj(b);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=log2(a[1]+1);i>=0;i--){
		int yy=0;//记录选取次数 
		bool vis[200005];
		for(int l=1;l<=n;l++){
			vis[l]=0;
		}
		for(int p=1;p<=n+1;p++){
			if(yy==m){
				for(int q=1;q<=n;q++){
					if(vis[q]==1){
						ans&=a[q];
					}
				}
				cout<<ans;
				return 0;
			}
			int bg=a[p]>>i;
			int k=bg&1;
			if(k==1){
				yy++;
				vis[p]=1;
			}
		}
	}
	cout<<ans;
	
	
	
	return 0;
}
