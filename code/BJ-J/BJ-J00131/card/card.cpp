#include<bits/stdc++.h>
using namespace std;
long long a[300005],ans[300005],n,m;;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		string t;
		bool vis[300005]={0};
		for(int j=i;j<=n;j++){
			int f=0;
			for(int q=0;q<int(t.size());q++){
				if(vis[q]==1){
					t[q]=a[j]+'0';
					vis[q]=0;
					vis[q+1]=1;
					f=1;
					break;
				}
				if(int(t[q]-'0')==a[j]){
					vis[q+1]=1;
					f=1;
					break;
				}
			}
			if(f==0)t+=char(a[j]+'0');
		}
		int w=0;
		while(vis[w]==0){
			ans[int(t[w]-'0')]++;
			w++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
