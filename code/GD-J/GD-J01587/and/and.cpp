#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int mp[N][32],n,m,t[N],sum,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1,v;i<=n;i++){
		cin>>v;
		int j=0;
		while(v){
			mp[i][j]=v%2;
			v/=2;
			j++;
		}
	}for(int i=30;i>=0;i--){
		sum=0;
		for(int j=1;j<=n;j++){
			sum+=t[j]==0?mp[j][i]:0;
		}
		if(sum>=m){
			ans+=pow(2,i);
			for(int j=1;j<=n;j++){
				t[j]=mp[j][i]==1?0:1;
			}
		}
	}cout<<ans;
	return 0;
}
