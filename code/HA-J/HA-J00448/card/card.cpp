#include<bits/stdc++.h>
using namespace std;
int n,m,t[5005],b[3005],pos[3005];
long long ans[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			b[i]=0;
		}
		
		for(int j=i;j<=n;j++){
			if(!b[t[j]]){
				b[t[j]]=1;
				pos[t[j]]=j;
			}
			else if(b[t[j]]){
				for(int k=pos[t[j]];k<j;k++){
					if(b[t[k]]){
						b[t[k]]=0;
					}
						
				}
				b[t[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
