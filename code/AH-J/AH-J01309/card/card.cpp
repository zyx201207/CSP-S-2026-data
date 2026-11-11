#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],t,check[N],d[N],ans[N];
vector<int> e;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	t=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int step=1;step<=n;step++) {
		memset(check,0,sizeof check);
		memset(d,0,sizeof d);
		for(int i=step;i<=n;i++) {
			if(check[a[i]]==0) check[a[i]]=i;
			else if(check[a[i]]!=0) {
				d[check[a[i]]] ++;
				d[i]--;
				for(int j=check[a[i]]+1;j<i;j++) check[a[j]]=0;
				check[a[i]]=i;
			} 
		}
		for(int i=step;i<=n;i++) {
			d[i]+=d[i-1];
			if(d[i]==0){
				ans[a[i]]++;
			}
		}
	}
	for(int i=1;i<=k;i++) cout<<ans[i]<<" ";
	return 0;
}


