#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a[N],ans[N],v[N];
int n,m; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0)v[a[j]]=j;
			else{
				for(int k=v[a[j]]+1;k<j;k++){
					v[a[k]]=0;
				}
				v[a[j]]=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(v[j]!=0)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
