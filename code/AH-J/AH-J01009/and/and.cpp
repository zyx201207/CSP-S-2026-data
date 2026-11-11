#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m,len=0;
int a[N],x[N][35],ans=0;
bool f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int y=a[i],cnt=1;
		while(y!=0){
			x[i][cnt++]=y%2;
			y/=2;
		}
		len=max(cnt,len);
	}
	for(int i=len-1;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(f[j]==0){
				if(x[j][i]==1){
					cnt++;
				}
			}
		}
		if(cnt>=m){
			ans+=pow(2,i-1);
			for(int j=1;j<=n;j++){
				if(f[j]==0){
					if(x[j][i]!=1){
						f[j]=-1;
					}
				}
			}
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
