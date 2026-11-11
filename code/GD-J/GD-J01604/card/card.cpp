#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
bool vis[N];
int sum[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n+5],sa[n+5],now=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			now++;
			if(vis[a[j]]==0){
				vis[a[j]]=1;
				sa[a[j]]=now;
			}else{
			    	for(int l=sa[a[j]]+1;l<=j+1;l++){
					vis[l]=0;
				}
			}
			
		}
		now=i;
		for(int j=1;j<=m;j++){
			if(vis[j]==1){
				sum[j]++;
				vis[j]=0;
			}
		} 
		
	}
	for(int i=1;i<=m;i++)
	    cout<<sum[i]<<' ';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

