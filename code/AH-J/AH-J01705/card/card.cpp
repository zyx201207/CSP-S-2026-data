#include<bits/stdc++.h>
using namespace std;
int s[1000001],f[1000001],ans[1000001],sum[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a="";
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		int q=0;
		memset(f,0,sizeof(f));
		memset(sum,0,sizeof(sum));
		for(int j=i;j<=n;j++){
			f[++q]=s[j];
			for(int k=1;k<=q;k++){
				if(f[j]==f[k]){
					memset(f,0,sizeof(f));
					q=1;
					f[q]=s[j-1];
				}
			}
		}
		for(int j=1;j<=q;j++){
			sum[f[j]]=1;
		}	
		for(int j=1;j<=m;j++){
			if(sum[j]==1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;

}
