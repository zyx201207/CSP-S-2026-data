#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[35],mx=0,ans=2147483647;
int t[200005];
vector<int> b[35];
void solve(int x){
	int t=x,i=1;
	while(x){
		if(x%2==1) f[i]++,b[i].push_back(t);
		x/=2;
		i++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],solve(a[i]);
	for(int i=35,t;i>=0;i--){
		if(f[i]>=m){
			sort(b[i].begin(),b[i].end());
			for(int j=b[i].size()-1;j>=b[i].size()-m;j--){
				ans&=b[i][j];
			}
			cout<<ans;
			return 0;
		}
	}
	cout<<0; 
}
