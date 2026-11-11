#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],maxx=0;
bool c[200005];
void search(int k){
	for(int i=b[k-1]+1;i<=n;i++){
		if(c[i]==0){
			c[i]=1;
			b[k]=i;
			if(k==m){
				long long ans=a[b[1]];
				for(int j=2;j<=m;j++) ans=ans&a[b[j]];
				maxx=max(maxx,ans);
			}
			else search(k+1);
			c[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	search(1);
	cout<<maxx;
	return 0;
}
