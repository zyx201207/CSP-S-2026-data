#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int l[500005];
int show[300005];
bool see[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int w=1;w<=n;w++){
		int xb=1,maxn=-1;
		for(int i=w;i<=n;i++){
			if(!see[a[i]]){
				l[xb]=a[i];
				see[a[i]]=1;
				xb++;
			}
			else{
				int cnt=0;
				for(int j=xb-1;j>=1;j--){
					cnt++;
					if(l[j]==a[i]) break;
					see[l[j]]=0;
					l[j]=0;
				}
				xb-=cnt;
				l[xb]=a[i];
				see[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(see[i]) show[i]++;
			see[i]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<show[i]<<" ";
	return 0;
}

