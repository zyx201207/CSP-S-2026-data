#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v(5e5+10);
	int dp[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=2;i<=n+1;i++){
		vector<int> v1;
		for(int j=i-1;j<=n;j++){
			int x=v[j],f=0;
			for(int z=0;z<v1.size();z++){
				if(v1[z]==x){
					f=1;
					int s=0;
					int res=v1.size();
					for(int z1=z;z1<res;z1++){
						v1.erase(v1.begin()+z);
						s++;
					}
					break;
				}
			}
			v1.push_back(x);
		}
		for(int z=0;z<v1.size();z++){
			dp[v1[z]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<dp[i]<<" ";
	}
	return 0;
}
