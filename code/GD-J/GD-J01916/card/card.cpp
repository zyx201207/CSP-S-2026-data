#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,cnt,a[N],b[N],c[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]>0){
				for(int k=cnt;k>=1;k--){
					b[c[k]]=0;
					if(c[k]==a[j]){
						cnt=k-1;
						break;
					}
				}
			}
			c[++cnt]=a[j];
			b[a[j]]=1;	
		}
		for(int j=1;j<=m;j++){
			if(b[j]>0)ans[j]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
