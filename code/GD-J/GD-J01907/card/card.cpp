#include<bits/stdc++.h>
using namespace std;
long long a[500005],res[300005],bji[300005];
bool sd[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(bji,-1,sizeof(bji));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		memset(sd,0,sizeof(sd));
		for(int j=i;j<n;j++){
			if(bji[a[j]]==-1)bji[a[j]]=j;
			else{
				for(int x=bji[a[j]];x<j;x++){
					sd[x]=1;
					bji[a[x]]=-1;
				}
				bji[a[j]]=j;
			}
		}
		for(int j=i;j<n;j++){
			if(sd[j]==0)res[a[j]]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
