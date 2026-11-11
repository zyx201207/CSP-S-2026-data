#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=5e5+100;
const int N2=3e5+100;
int n,m;
int cnt[N2];
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int>lat(m+1,0);
		vector<bool>vis(n+1,0);
		for(int j=i;j<=n;j++){
			if(lat[a[j]]){
				for(int k=lat[a[j]];k<j;k++){
					vis[k]=1;
				}
				lat[a[j]]=0;
			}
			else{	
				lat[a[j]]=j;
			}
		}
		vector<bool>num_vis(N2,0);
		for(int j=i;j<=n;j++){
			if(!vis[j]&&!num_vis[a[j]]){
				cnt[a[j]]++;
				num_vis[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

