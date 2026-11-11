#include<iostream>
#include<cstring>
#include<cmath>
#define int long long
using namespace std;
const int N=3e5+10;
int n,m;
int a[N];
int bit[N][35];
int sum[35];
bool f[N];
int ans[35];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int tmp=a[i];
		for(int j=1;j<=31;j++){
			bit[i][j]=tmp&1;
			tmp/=2;
		}
	}
	for(int j=1;j<=31;j++){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=bit[i][j];
		}
		sum[j]=cnt;
	}
	
	for(int j=31;j>=1;j--){
		if(sum[j]<m){
			continue;
			ans[j]=0;
		}else{
			ans[j]=1;
			for(int i=1;i<=n;i++){
				if(bit[i][j]==0&&f[i]==false){
					f[i]=true;//±»ÌÔÌ­ÁË
					for(int k=1;k<=31;k++){
						sum[k]-=bit[i][k];
					} 
				}
			}
		}
	}
	int res=0;
	for(int i=31;i>=1;i--){
		res=res*2+ans[i];
	}cout<<res;
	return 0;
}
