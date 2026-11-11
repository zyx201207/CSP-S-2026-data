#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool vis[500005];
int t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>0;i--){
		t[a[i]]++;
		vis[a[i]]=1;
		for(int j=n;j>=i;j--){
			if(a[i]==a[j]&&vis[a[j]]==true){
				for(int k=j;k<=n;k++){
					vis[k]=false;
				}
			}else if(vis[a[j]]==true){
				t[a[j]]++;
			}else{

			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
}
