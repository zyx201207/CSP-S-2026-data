#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		maxx[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m-1;j++){
			long long b=maxx[j],c=a[i],sum=0,jj=1;
			while(b>0||c>0){
				if(b%2==c%2){
					sum+=jj*(b%2);
				}
				jj*=2;
				b/=2;
				c/=2;	
			}
			maxx[j+1]=max(maxx[i],sum);
		}
	}
	cout<<maxx[m];
	return 0;
}
