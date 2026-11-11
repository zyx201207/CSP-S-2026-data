#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long n,m,a[N],a1[N],b[N],c[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) a1[i]=i;
	long long n1=n,ls=1;
	while(n1--){
		if(n1<0 || ls>n) break;
		long long e=1;
		for(int i=1;i<=n;i++) b[i]=a[i];
		c[e]=b[ls]; 
		e++;
		for(int i=ls+1;i<=n;i++){
			for(int j=i-1;j>=i-abs(e-i)-1;j--){
				if(b[j]==b[i] && b[j]!=-1 && b[i]!=-1){
					for(int k=j;k<=i-1;k++) b[k]=-1;
					e-=(i-j);
				}
			}
			c[e]=b[i];
			e++;
		}
		for(int i=1;i<=m;i++) for(int j=1;j<e;j++) if(c[j]==a1[i]) d[i]++;
		ls++;
	}
	for(int i=1;i<=m;i++) cout<<d[i]<<" ";
	return 0;
}
