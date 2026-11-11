#include<bits/stdc++.h>
using namespace std;

int a[500005];
int ans[300005];
int c[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	int tot=0;
	for(int t=1;t<=n;t++){
		for(int i=1;i<=tot;i++) c[i]=0;
		
		for(int i=t;i<=n;i++){
			bool f=false;
			for(int j=1;j<=tot;j++){
				if(c[j]==a[i]){
					for(int k=j;k<=tot;k++) c[k]=0;
					tot=j;
					c[tot]=a[i];
					f=true;
					break;
				}
			}
			if(!f) c[++tot]=a[i];
		}
		
		for(int i=1;i<=tot;i++) ans[c[i]]++;
	}
	
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
