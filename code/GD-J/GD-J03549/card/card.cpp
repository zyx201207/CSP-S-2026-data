#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,M=3e5+7;;
int n,m,a[N],res[M],li[M],x[N];
bool c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<n;i++) if(a[i]<a[i-1]) f=0;
	if(f) for(int i=0;i<n;i++) res[a[i]]=max(res[a[i]],i+1);
	else{
		for(int i=0;i<n;i++){
			int r=0;
			memset(li,-1,sizeof(li));
			memset(c,0,sizeof(c));
			for(int j=i;j<n;j++){
				x[r]=a[j];
				if(li[a[j]]==-1) li[a[j]]=r,c[a[j]]=1;
				else{
					for(int k=li[a[j]];k<r;k++) li[x[k]]=-1,c[a[j]]=0;
					li[a[j]]=r;
				}
				r++;
			}
			for(int j=0;j<r;j++) if(c[x[j]]) res[x[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<res[i]<<" ";
	return 0;
}
