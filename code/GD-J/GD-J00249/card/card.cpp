#include <bits/stdc++.h>
using namespace std;

int n,m,a[500010],ans[300010],b[500010],cnt,nn;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	nn=n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(nn--){
		cnt++;
		for(int i=1;i<=n;i++)
			b[i]=a[i];
		for(int i=cnt;i<=n;i++){
			for(int j=cnt;j<i;j++)
				if(b[j]==b[i])
					for(int k=j;k<i;k++)
						b[k]=0;
		}
		for(int i=cnt;i<=n;i++){
			if(b[i]!=0)
				ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
