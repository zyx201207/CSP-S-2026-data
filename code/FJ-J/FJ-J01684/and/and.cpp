#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int MAXN=1e2+5;
int n,m;
int a[N];
bool flag[N];
bool two[N][MAXN];
int sum[N];
int t=-1;
int tj=0;
int minn;
int ans=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag[i]=true;
		int x=a[i];
		int num=1;
		if(x==0){
			two[i][num]=false;
			num++;
		}
		while(x){
			two[i][num]=x%2;
			x/=2;
			num++;
		}
		num--;
		sum[i]=num;
		if(sum[1]>t){
			t=sum[i];
		}
	}
	for(int i=t;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(sum[j]>=i){
				tj++;
			}
		}
		if(tj>=m){
			minn=i+0;
			for(int j=1;j<=n;j++){
				if(sum[j]<i){
					flag[j]=false;
				}
			}
			break;
		}
		tj=0;
	}
	for(int j=minn;j>=1;j--){
		for(int i=1;i<=n;i++){
			if(flag[i]&&two[i][j]){
				tj++;
			}
			if(flag[i]&&!two[i][j]){
				tj++;
			}
		}
		if(tj>=m){
			for(int i=1;i<=n;i++){
				if(flag[i]&&!two[i][j]){
					flag[i]=false;
				}
			}
			ans+=pow(2,j); 
		}
	}
	cout<<ans;
	return 0;
}
