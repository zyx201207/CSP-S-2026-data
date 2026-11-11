#include<bits/stdc++.h>
using namespace std;
struct lz{
	int k,id;
}a[500005];
int n,m,f[500005],ans[300005],b[500005],cnt;
bool cmp(lz x,lz y){
	if(x.k!=y.k)return x.k<y.k;
	return x.id<y.id;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[i].k=b[i];
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		int l=1,r=n,pos=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[mid].k==b[i]){
				if(a[mid].id<=i){
					l=mid+1;
				}else{
					pos=a[mid].id;
					l=mid+1;
				}
			}else if(a[mid].k<b[i]){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		f[i]=pos;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			ans[b[j]]++;
			if(f[j]!=-1){
				j=f[j]+1;
				continue;
			}
			j++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
