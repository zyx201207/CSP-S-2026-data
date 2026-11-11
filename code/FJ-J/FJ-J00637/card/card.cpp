#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans[200005],bj[200005],b[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	} 
	for(int j=1;j<=n;j++){
		memset(bj,0,sizeof(bj));
		for(int i=j;i<=n;i++){
			b[i]=a[i];
			if(bj[b[i]]>=1){
				for(int x=bj[a[i]];x<=i-1;x++){
					bj[b[x]]=0; 
					b[x]=0;
				} 
				
			}
			bj[b[i]]=i;
		}
		int bj2=0;
		for(int i=j;i<=n;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
