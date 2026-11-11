#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],f[500005],ans;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=i,r=n;      //k表打的第几张牌 
		ans=0;
		memset(f,0,sizeof f);
		for(int j=i;j<=n;j++) f[j]=1;
		for(int j=1;j<=n;j++) b[j]=a[j];
		while(k<=n){
			int p=0;
			for(int j=1;j<=n;j++) if(b[j]==k&&f[j]) p=j;
			if(p==0) b[++r]=k;
			else{
				for(int j=p+1;j<=n;j++) f[j]=0;
				r=p;
			}
			if(b[r]==i) ans++;
			k++;
		}
		if(ans) cout<<ans<<' ';
	}
}
