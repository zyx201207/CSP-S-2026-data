#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int mn[500050];
int ans[500050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int f=0;
		memset(mn,0,sizeof(mn));
		for(int j=i;j<=n;j++){
			int s=a[j];
			bool b=true;
			for(int k=1;k<=f;k++){
				if(mn[k]==s){
					f=k;
					b=false;
					continue;
				}
				if(!b){
					mn[k]=0;
				}
			}
			if(b){
				f++;
				mn[f]=s;
			}
		}
		for(int j=1;j<=f;j++){
			ans[mn[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
