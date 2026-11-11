#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500000];
int ans[500000];
int b[500000];
int n,m;
int find(int x,int r){
	for(int i=0;i<r;i++){
		if(b[i]==x){
			return i;
		}
	}
	return -1;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b[j]=0;
		}
		int r=0;
		for(int j=i;j<n;j++){
			int pl=find(a[j],r);
			if(pl==-1||r==0){
				b[r]=a[j];
				r++;
			}else{
				r=pl+1;
			}
		}
		for(int i=0;i<r;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
