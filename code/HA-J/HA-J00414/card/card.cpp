//4
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005],bj[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=false;
		bj[a[i]]=max(i,bj[a[i]]);
	}
	if(flag==true){
		for(int i=1;i<=m;i++){
			cout<<bj[i]<<" ";
		}
		return 0;
	}
	memset(bj,0,sizeof(bj));
	for(int k=1;k<=n;k++){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int dir=1;
		for(int i=k;i<=n;i++){
			if(c[a[i]]==0){
				b[dir]=a[i];
				c[a[i]]=dir;
				dir++;
			}else{
				for(int j=c[a[i]]+1;j<dir;j++){
					c[b[j]]=0;
					b[j]=0;
				}
				dir=c[a[i]]+1;
			}
		}
		for(int i=1;i<dir;i++){
			bj[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<bj[i]<<" ";
	}
	return 0;
}
