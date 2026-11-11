#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int id[300005]={},q=-1;
		for(int j=i;j<n;j++){
			if(!id[a[j]]){
				id[a[j]]=1;
				b[++q]=a[j];
			}
			else {
				while(b[q]!=a[j]){
					id[b[q]]=0,b[q--]=0;
				}
				q++;
			}
		}
		for(int j=1;j<=m ;j++)ans[j]+=id[j];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
