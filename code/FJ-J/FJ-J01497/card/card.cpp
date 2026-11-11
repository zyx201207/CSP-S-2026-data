#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[300005],d[300005],q[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++) {
		memset(d,0,sizeof(d));x=0;
		for(int i=k;i<=n;i++) {
			bool f=1;
			for(int j=1;j<=x;j++)
				if(a[j]==a[i]) {
					for(int l=j;l<=x;l++) a[l]=0;
					f=0;
				}
			if(f==1) d[++x]=a[i];
		}
		for(int i=1;i<=x;i++) q[d[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<q[i]<<" ";
	return 0;
}
