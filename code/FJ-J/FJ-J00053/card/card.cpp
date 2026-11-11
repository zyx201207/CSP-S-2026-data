#include <bits/stdc++.h>
using namespace std;

int a[500002],b[500002],c[500002],ans[300002];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			b[j]=0;
		}
		int cnt=0;
		for (int j=i;j<=n;j++){
			if (b[a[j]]==0||b[a[j]]>cnt){
				cnt++;
				b[a[j]]=cnt;
				c[cnt]=a[j];
			}
			else{
				cnt=b[a[j]];
			}
		}
		for (int j=1;j<=cnt;j++){
			ans[c[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

