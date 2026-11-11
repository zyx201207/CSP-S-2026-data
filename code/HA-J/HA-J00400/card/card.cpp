#include<bits/stdc++.h>
using namespace std;
struct zimu{
	int timenow;
	int num;
}z[500005];
int m,n;
int nowc[500005],sum[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>z[i].num ;
    	sum[z[i].num]++;
	}
	int w=0;
	for(int i=1;i<=n;i++){
		nowc[z[i].num ]++;
		if(nowc[z[i].num ]==sum[z[i].num ] && sum[z[i].num ]>1){
			w--;
		}
		if(nowc[z[i].num ]==1 && sum[z[i].num ]>1){
			z[i].timenow =0;
			w++;
			continue;
		}
		if(i==n){
			z[i].timenow =n;
		}
		z[i].timenow =i-w;
	}
  for(int i=1;i<=n;i++){
  	ans[z[i].num]=ans[z[i].num]+z[i].timenow ;
	}
	for(int i=1;i<=m;i++){
		if(ans[i]>0){
		cout<<ans[i]<<" ";
	}
}
		return 0;
}
