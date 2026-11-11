#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500007],b[500007],ans[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int x=1;x<=n;x++){
		for(int i=1;i<=m+7;i++) b[i]=0;
		for(int i=x,j=1;i<=n;i++,j++){
			long long p=0;
			b[j]=a[i];
			bool is=true;
			for(int y=1;y<j;y++) if(b[y]==b[j]){is=false;p=y;break;}
			if(!is){
				for(int y=p+1;y<=j;y++) b[y]=0;
				j=p;
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i]!=0) ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
