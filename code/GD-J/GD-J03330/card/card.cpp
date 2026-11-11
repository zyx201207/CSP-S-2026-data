#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[m+1]={0};
	for(int i=1;i<=n;i++){
		int c[n+1]={0};
		for(int j=i;j<=n;j++){
			for(int l=i;l<j;l++){
				if(a[l]==a[j]&&c[l]==0){
					for(int x=l;x<j;x++){
						c[x]=1;
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(c[j]==0)
			b[a[j]]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
}

