#include <bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<n;i++){
		int flag=a[i],j=i,k=i+1;
		while(j<=n&&k<=n){
			if(a[k]==flag){
				b[j]--;
				b[k]++;
				j=k;
			}
			k++;
		}
//		cout<<j<<" ";
		int p=j+1,q=n;
		for(;p<n;){
			if(p>=q){
				p++;
				q=n;
			}
			if(a[p]==a[q]){
				b[p]--;
				b[q]++;
				p=q;
				q=n;
			}else{
				q--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i]+1+b[i-1];
//		cout<<b[i]<<" ";
		cnt[a[i]]=max(cnt[a[i]],b[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
