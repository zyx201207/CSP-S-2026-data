#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],ans[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[N]={};
		for(int j=1;j<=n;j++){
			vis[j]=0;
		}
		int idx=0;
		for(int j=i;j<=n;j++){
			idx++;
			b[idx]=a[j];
		}
		vector<int>v;
		int c[N],cnt=0;
		for(int j=1;j<=idx;j++){
			if(vis[b[j]]==1){
				cnt++;
				bool ff=1;
				for(int k=1;k<=cnt;k++){
					if(ff==0)break;
					if(c[k]==b[j]){
						for(int p=k;p<=cnt;p++){
							c[p]=0;
							ff=0;
						}
					}
				}
				c[cnt]=b[j];
			}else{
				cnt++;
				c[cnt]=b[j];
				vis[b[j]]=1;
			}
		}
		for(int j=1;j<=cnt;j++){
			ans[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
