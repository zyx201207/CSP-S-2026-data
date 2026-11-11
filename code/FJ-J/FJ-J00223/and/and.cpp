#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[202020];
bool p[201010][40];
bool vis[202020];
int ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int tmp=0;
	for(int i=1;i<=n;i++){
		tmp=pow(2,30);
		for(int j=30;j>=0;j--){
		//	cout<<tmp<<endl;
			if(a[i]>=tmp){
				a[i]-=tmp;
				p[i][j]=1;
//				cout<<1;
			}else{
//				cout<<0;
			}
			tmp/=2;
		}
//		cout<<endl;
	}
	tmp=0;
	for(int i=35;i>=0;i--){
		tmp=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&p[j][i]==1){
				tmp++;
			}
		}
		if(tmp<m){
			continue;
		}else{
			ans+=pow(2,i);
		}
		for(int j=1;j<=n;j++){
			if(p[j][i]==0){
				vis[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
//000000011
//000001111
//000001100
//000001100

