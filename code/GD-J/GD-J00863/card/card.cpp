#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
bool check(vector<int>vt,int x){
	for(int y:vt)if(x==y)return 0;
	return 1;
}
bool checkA(vector<int>a,int n){
	for(int i=1;i<n;i++)if(a[i]>a[i+1])return 0;
	return 1;
}
int dis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<int>a(n+5);
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=500){
		for(int l=1;l<=n;l++){
			vector<int>vt;
			for(int i=l;i<=n;i++){
				if(check(vt,a[i]))vt.push_back(a[i]);
				else {
					while(vt[vt.size()-1]!=a[i])vt.pop_back();
				}
			}
			for(int x:vt)dis[x]++;
		}
	}
	else if(checkA(a,n)){
		vector<int>dis2(m+5);
		for(int l=1;l<=n;l++){
			for(int i=l;i<=n;i++){
				if(dis2[a[i]]==0)
					dis2[a[i]]=1,dis[a[i]]++;
			}
			for(int i=l;i<=n;i++)
				dis2[a[i]]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<dis[i]<<" ";
	return 0;
}
