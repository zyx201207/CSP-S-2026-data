#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005][35];
void find(int x,int i){
	int l=x,cnt=0;
	while(l){
		if(l%2==1){
			a[i][cnt]=1;
		}
		l/=2;
		cnt++;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int q;
		cin>>q;
		find(q,i);
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]==1){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(a[j][i]==0){
					for(int k=0;k<=30;k++){
						a[j][k]=0;
					}
				}
			}
			ans+=pow(2,i);
		}
	}
	cout<<ans;
	return 0;
}
