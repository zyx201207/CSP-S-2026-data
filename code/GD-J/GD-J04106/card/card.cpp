#include<bits/stdc++.h>
using namespace std;
int a[500005],kl[500005],b[500005],c[500005];
int bj[500005],bj2[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans=0;cin>>n>>m;
	int i,j,k;
	for(i=1;i<=n;i++) cin>>a[i],c[i]=a[i];
	sort(c+1,c+n+1);
	for(i=1;i<=n;i++)
		if(c[i]==a[i]) ans++;
	if(ans==n){
		for(i=1;i<=m;i++) cout<<n<<' ';
		return 0;
	}else
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++) kl[j+1-i]=a[j];
		for(j=n+1;j<500001;j++) kl[j+1-i]=0;
		for(k=1;k<=n+1-i;k++){
			bj[kl[k]]++;
			if(bj[kl[k]]==2)
			for(int l=bj2[kl[k]];l<=n;l++)
				kl[l]=kl[l+(k-bj2[kl[k]]+1)];
			bj2[kl[k]]=k;
		}
		for(j=0;j<=500001;j++) b[kl[j]]++;
		for(j=n+1;j<500001;j++) kl[j]=0;
	}
	for(i=1;i<=m;i++) cout<<b[i]<<' ';	
	return 0;
}
