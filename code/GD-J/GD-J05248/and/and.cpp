#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,a[200001];
long long ans=0,d[200001],c[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	cnt=m-1;
	memset(c,1,sizeof(c));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[i]=a[i];c[i]=d[i];
	}
	while(cnt>0){
		for(int i=1;i<=n;i++){
			long long k=0;
			for(int j=1;j<i;j++){
				if(i<m+1-cnt){d[i]=c[i];break;}
				else k=max(k,c[j]&a[i]);
			}
			d[i]=k;
		}
		for(int i=1;i<=n;i++)c[i]=d[i];
		cnt--;
	}
	for(int i=1;i<=n;i++)ans=max(ans,d[i]);
	printf("%lld",ans);
	return 0;
}
