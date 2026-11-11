#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],c[35],d[200005],x,cnt,v[300005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n>>m;
	d[1]=1;
	for(int i=2;i<=30;i++){
		d[i]=d[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=a[i];
		cnt=0;
		while(x){
			c[++cnt]+=x%2;
			x/=2;
		}
	}
	for(int i=30;i>=1;i--){
		if(c[i]>=m){
			ans+=d[i];
			for(int j=1;j<=n;j++){
				if(a[j]>=ans){
					v[j]=i;
				}
			}
			memset(c,0,sizeof(c));
			for(int j=1;j<=n;j++){
				if(v[j]==i){
					x=a[j];cnt=0;
					while(x){
						c[++cnt]+=x%2;
						x/=2;
					}
				}
				else{
					a[j]=0;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
