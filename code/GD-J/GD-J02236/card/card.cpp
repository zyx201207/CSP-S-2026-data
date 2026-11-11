#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N],c[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=1;j<=n;j++){
			b[a[j]]=0;
			c[a[j]]=0;
		}
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				b[a[j]]=x;
				c[++x]=a[j];
			}
			else{
				for(int k=b[a[j]]+1;k<=x;k++){
					c[k]=0;
					b[c[k]]=0;
				}
				x=b[a[j]];
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j])d[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<" ";
	return 0;
}
