#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,w[200010],m,k[200010],st;
bool aa[200010],booans[200010],vis[200010];
bool A=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>m>>n;
	for(int i=1;i<m+1;i++){
		cin>>w[i];
		if(w[i]<w[i-1]){
			A=0;
		}
	}
	if(A){
		for(int i=1;i<n+1;i++){
			cout<<m<<" ";
		}
		return 0;
	}
	for(int i=1;i<m+1;i++){
		memset(vis,1,sizeof(vis));
		memset(aa,1,sizeof(aa));
		memset(booans,0,sizeof(booans));
		for(int j=i;j<m+1;j++){
			for(int l=i;l<j;l++){
				if(w[l]==w[j]&&vis[l]!=0){
					for(int r=l;r<j;r++){
						aa[r]=0;
						vis[r]=0;
					}
					break;
				}
			}
		}
		for(int j=i;j<m+1;j++){
			if(aa[j]){
				if(!booans[w[j]]){
					k[w[j]]++;
					booans[w[j]]=1;
				}
			}
		} 
	}
	for(int i=1;i<n+1;i++){
		cout<<k[i]<<" ";
	}
	return 0;
}

