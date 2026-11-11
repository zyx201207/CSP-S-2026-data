#include <bits/stdc++.h>
using namespace std;
const int  N=1e6;

long long n,m,a[N],b[N],ans[N],j;

int main (){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
cin >>n>>m;
for (int i=1;i<=n;i++) {
	cin >>a[i];
	b[i]=a[i];
}
for (int i=1;i<=n;i++){
	j=i;
	while (j<=n){
		int k;
		int l=j,r=n,cnt=0;
		while (l<=r){
			int mid=(l+r)/2;
			if (mid>=a[j]){
				if (mid==a[j]) cnt=mid;
				r=mid-1;
			}
			else l=mid+1; 
		}
	    if (cnt>0) j=cnt;
	    else{
	    	j++;
	    	if (k[a[j]]==0) ans[a[j]]++;
	    	k[a[j]]=1;
	    }
		}
}
for (int i=1;i<=m;i++){
	cout <<ans[i]<<' ';
}
	return 0;
}
