#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans;
int n,m;
int a[200001];
bool v[100001];
int sum[200001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){	
			if(v[a[j]]){
				int p;
				for(int k=j-1;k>=i;k--){
					if(v[a[k]]==v[a[i]]){
						p=k;
						break;
					}
				}
				for(int k=p;k<=j;k++){
					v[a[k]]=0;
				}
			}
			v[a[j]]=1;
		}
		for(int k=i;k<=n;k++){
			if(v[a[k]])sum[a[k]]++;
			v[a[k]]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
