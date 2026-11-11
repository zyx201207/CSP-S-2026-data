#include<bits/stdc++.h>
using namespace std;
int const maxn=5e5+5;
int n,m;
int a[5000];
int cha[5000][5000];
int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cha[i][j]=abs(a[i]-a[j]);
		}
	}
	int k=1;
	int ans[5000];
	sort (a+1,a+n+1);
	for (int i=1;i<=n;i++){
		int x[5000];
		for (int j=1;j<=n;j++){
			x[j]=cha[i][j];
		}
		sort(x+1,x+n+1);
		int cnt[5000]; 
		memset (cnt,0,sizeof(cnt));
		for (int j=1;j<=n;j++){
			cnt[j]=cnt[j-1]+x[j];
		}
		int sum=0;
		for (int j=1;j<=n;j++){
			if (cnt[j]<=m&&cnt[j+1]>m){
				ans[k]=j;
				k++;
				break;
			}
		}
	}
	int maxx=-1;
	for (int i=1;i<=n;i++){
		maxx=max(maxx,ans[i]);
	}
	cout<<maxx<<endl;
	return 0;
}
