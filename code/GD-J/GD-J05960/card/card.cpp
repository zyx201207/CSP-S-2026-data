#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[1000086],vis[10000086],sum[10000086];
vector<ll>v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(vis[a[j]]){
				for(int k=j-1;k>=0&&!v.empty();k--){
					if(v.back()==a[j]){
						break;
					}
					vis[v.back()]=0;
					v.pop_back();
				}
			}else{
				v.push_back(a[j]);
				vis[a[j]]=1;
			}
		}
		for(int j=0;j<v.size();j++){
			sum[v[j]]++;
		}
		while(!v.empty()){
			v.pop_back();
		}
		for(int j=0;j<n;j++){
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
