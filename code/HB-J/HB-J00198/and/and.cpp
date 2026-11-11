#include<bits/stdc++.h>
using namespace std;
int a[200005],t[200005];
int s[32][200005];
int sum[32];
bool v[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		int k=1;
		while(a[i]){
			s[k][i]=a[i]%2;
			k++;
			a[i]/=2;
		}
	}
	for(int i=1;i<=29;i++){
		for(int j=1;j<=n;j++){
			sum[i]+=s[i][j];
		}
	}
	for(int i=29;i>=1;i--){
		if(sum[i]>m){
			for(int j=1;j<=i;j++){
				for(int k=1;k<=n;k++){
					if(s[i][k]==0){
						v[k]=1;
						sum[i]-=s[i][j];
					}
				}
			}
		}else if(sum[i]==m){
			int ans=INT_MAX;
			for(int j=1;j<=n;j++){
				if(s[i][j]==1){
					ans=ans&t[j];
				}
			}
			cout<<ans;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
