#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int l[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(l,0,sizeof(l));
		for(int j=i;j<=n;j++){
			if(!l[a[j]]){
				l[a[j]]=j;
			}
			else{
				int t=l[a[j]];
				for(int k=1;k<=m;k++){
					if(l[k]>t){
						l[k]=0;
					}
				}
				l[a[j]]=j;
			}
		}
		for(int i=1;i<=m;i++){
			if(l[i]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
