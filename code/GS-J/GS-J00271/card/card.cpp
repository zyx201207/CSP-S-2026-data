#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int f[300005];
int ff[300005];
int a[500005];
pair<int,int> w[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f[a[i]]==1){
			w[a[i]].second=i;
			f[a[i]]+=1;
		}
		else if(f[a[i]]>1){
			w[a[i]].first=w[a[i]].second;
			w[a[i]].second=i;
			f[a[i]]+=1;
		}
		else{
			f[a[i]]+=1;
			w[a[i]].first=i;
		}
	}
	for(int i=1;i<=n;i++){
		int max1=-1;

		for(int j=1;j<=m;j++){
			if(w[j].first<i){
				w[j].first=w[j].second;
				w[j].second=-1;
			}
			if(f[j]%2==0){
				max1=max(max1,w[j].second);
			}
			
		}
		if(max1>i){
			for(int j=max1;j<=n;j++){
				ff[a[j]]+=1;
			}
		}
		else{
			for(int j=i;j<=n;j++){
				ff[a[j]]+=1;
			}
		}
		f[a[i]]--;
	}
	for(int i=1;i<=m;i++){
		cout<<ff[i]<<' ';
	}
	return 0;
}
