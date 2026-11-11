#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],first[300005],ans[300005];
int q[500005],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				if(first[a[j]]==0) first[a[j]]=++cnt,q[cnt]=a[j];
				else{
					//cout<<"cnt:" <<cnt<<' '<<"i:"<<i<<" j:"<<j<<' ';
					for(int k=first[a[j]]+1;k<=cnt;++k){
						first[q[k]]=0;
					}
					cnt=first[a[j]];				
				}
			}
			for(int j=1;j<=cnt;++j) {
				ans[q[j]]++;
				//cout<<"q["<<j<<"]="<<q[j]<<' ';
			}
			//cout<<'\n';
			cnt=0;
			fill(first+1,first+m+1,0);
		}
		for(int j=1;j<=m;++j){
			cout<<ans[j]<<' ';
		}
	return 0;
}
