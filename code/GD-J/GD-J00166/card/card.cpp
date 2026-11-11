#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],w[N],ans[N],v[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(w,0,sizeof(w));
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			for(int p=i;p<j;p++)
				if(a[p]==a[j]&&v[p]!=1)
					for(int k=p;k<j;k++)
						v[k]=1;
		}
		for(int j=i,f=1;j<=n;j++){
			if(v[j]==1)
				continue;
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
