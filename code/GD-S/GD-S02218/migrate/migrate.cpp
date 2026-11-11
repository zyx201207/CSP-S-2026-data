#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,a[N],p[N],b[N],len;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		int ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+3; j<=n; j++) {
				bool vis=0;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[k-1]>d){
						vis=1;
						break;
					}
				}
				if(vis==1) continue;
				for(int k=1; k<=len; k++) b[k]=0;
				len=0;
				b[++len]=i;
				for(int k=i+1; k<=j; k++) {
					if(a[k]-a[b[len]]>d) {
						b[++len]=k-1;
					}
				}
				b[++len]=j;
//				if(i==1&&j==5){
//					for(int k=1;k<=len;k++){
//						cout<<b[k]<<" ";
//					}
//				}
				long long flag=0;
				for(int k=2;k<=len-1;k++){
					int l=lower_bound(a+1,a+n+1,a[b[k+1]]-d)-a;
					int r=lower_bound(a+1,a+n+1,a[b[k-1]]+d)-a;
					flag+=(r-l+1);
				}
				if(flag==2){
				    ans++;
			    }
			}
		}
		cout<<ans<<'\n';
	}

}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
