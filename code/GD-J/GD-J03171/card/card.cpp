#include<bits/stdc++.h>
const int N=5*1e3+5,M=3*1e3+5;
using namespace std;
int a[N];
int cnt[M],ans[M],first[M];
map<int,bool> mp[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(first[a[i]]==0){
			first[a[i]]=i;
			for(int j=1;j<=m;j++){
				ans[j]+=mp[i+1][j];
				mp[i][j]=mp[i+1][j];
			}
			mp[i][a[i]]=1;
			ans[a[i]]++; 
		}else{
			for(int j=1;j<=m;j++){
				ans[j]+=mp[first[a[i]]][j];
				mp[i][j]=mp[first[a[i]]][j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

