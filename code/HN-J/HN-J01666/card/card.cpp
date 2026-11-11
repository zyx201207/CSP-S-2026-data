#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int N1=3e5+5;
int n,m;
int a[N];
int z[N1];
struct node{
	bool b;
	int v;
};
node vis[N1];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int o=1;o<=m;o++){
			vis[o].b=0;
			vis[o].v=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]].b){
				for(int l=vis[a[j]].v;l<j;l++){
					vis[a[l]].b=0;
				}
			}
			vis[a[j]].b=1;
			vis[a[j]].v=j;
		}
		for(int i=1;i<=m;i++){
			//cout<<i<<":"<<vis[i].b<<endl;
			if(vis[i].b){
				z[i]++;
			}
		}
		cout<<endl; 
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<" ";
	}
	return 0; 
}
