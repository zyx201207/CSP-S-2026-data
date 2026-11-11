#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e3;
int c,t,n,d;
int a[N];
int m[N][N],cnt[N][N];
void f(int be,int p,int w){
	if(w>m[be][p])return;
	//printf("从%d起飞 飞到了%d 当前长度%d\n",be,p,w);
	if(p==n)return;
	for(int i=p+1;i<=n;++i){//直接飞 
		int wd=a[i]-a[p];
		if(wd>d)break;
		if(w+1<m[be][i]){
			cnt[be][i]=1;
			m[be][i]=w+1;
		}
		else if(w+1==m[be][i])cnt[be][i]++;
		f(be,i,w+1);//间接飞 
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
			m[i][j]=2e18+100;
			cnt[i][j]=0;
		}
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<n;++i){
			f(i,i,0);//不同起点;
			for(int j=i+1;j<=n;++j){
				if(cnt[i][j]==2){
					ans++;
				//	printf("%d %d是一对\n",i,j); 
				}
			}
		}
		cout<<ans<<endl; 
	}
}
