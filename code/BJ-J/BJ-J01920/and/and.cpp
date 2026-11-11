#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
int a[maxn];
int c[maxn][35];
int cnt[maxn];
map<long long,int>mp;
int mx=0;
int ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<(1&3);
	for(int i=1;i<=n;i++){
		int k=1;
		for(int j=0;j<31;j++){
			if(a[i]&k){
				c[i][j]=1;
				cnt[j]++;			
			}else{
				c[i][j]=0;
			}
			k*=2;
			//cout<<c[i][j];
		}
		//cout<<"\n";
	}
	//cout<<cnt[0]<<" "<<cnt[2];
	for(int j=30;j>=0;j--){
		if(cnt[j]>=m){
			//cout<<j<<"dd";
			ans+=(1<<j);		
			for(int i=1;i<=n;i++){
				if(c[i][j]==0){
					for(int k=j;k>=0;k--){
						if(c[i][k])cnt[k]--;
					}
				}
			}	
		}

	}
	cout<<ans;
	return 0;
}
