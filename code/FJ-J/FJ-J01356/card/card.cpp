#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[300005],len,di[300005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		len=0;
		for(long long j=0;j<=m;j++){
			d[j]=-1;
			di[j]=-1;
		}
		for(long long j=i;j<n;j++){
			if(di[a[j]]==-1){
				di[a[j]]=len++;
				d[len-1]=a[j];
			}else{
				for(long long k=di[a[j]]+1;k<len;k++){
					di[d[k]]=-1;
					d[k]=-1;
				}
				len=di[a[j]]+1;
			}
		}
		for(long long j=1;j<=m;j++){
			cnt[j]+=(di[j]!=-1);
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}