#include<bits/stdc++.h>
using namespace std;
long long a[5000010],b[5000010],n=0,m=0,ans[5000010];
bool c[5000010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	const int m1=m,n1=n;
	for(int i=1;i<=m1;i++){
		c[i]=0;
	}
	for(int i=1;i<=n1;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n1;i++){
		for(int j=i;j<=n1;j++){
			b[j]=a[j];
		}
		long long l=i,r=-1;
		for(int j=i;j<=n1;j++){
			if(c[b[j]]==1&&b[j]!=-1){
				for(int k=j-1;k>=l;k--){
					if(b[j]==b[k]){
						l=k;
						r=j-1;
						break;
					}
				}
				for(int k=l;k<=r;k++){
					b[k]=-1;
				}
				l=i;
				r=-1;
			}
			if(b[j]!=-1){
				c[b[j]]=1;
			}
		}
		for(int j=i;j<=n1;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m1;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
