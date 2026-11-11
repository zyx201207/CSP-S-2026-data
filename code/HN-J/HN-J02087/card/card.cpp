#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],st[500005],k[300005],idx;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++){
		idx=1;
		memset(st,0,sizeof st);
		memset(k,0,sizeof k);
		for(long long j=i;j<=n;i++){
			if(k[a[j]]){
				bool f=0;
				while(!f){
					if(st[idx]==a[j]) f=1;
					idx--;
				}
			}else st[++idx]=a[j],k[a[j]]=1;
		}
		for(long long j=1;j<=n-i;j++) b[j]++;
	}
	for(long long i=1;i<=m;i++) cout<<b[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
