#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a1;
const int N=2e5+10,M=3e5+10;;
int a[N],b[N],c[M],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[j]=0;
		}
		cnt=0;
		for(int j=i;j<=n;j++){
			if(c[a[j]]==1){
				for(int k=1;k<=cnt;k++){
					if(b[k]==a[j]){
						a1=cnt;
						cnt=k-1;
						break;
					}
				}
				for(int k=cnt+1;k<=a1;k++){
					c[b[k]]=0;
				}
			}
			b[++cnt]=a[j];
			c[a[j]]=1;
		}
		for(int j=1;j<=cnt;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
