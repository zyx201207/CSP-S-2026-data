#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=m;i<=n){
		int k = rand()%n;
	}
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],q[500005];
int check(int l,int r,int x){
	while(l<=r){
		int mid = (a[q[l]]+a[q[r]])/2;
		if(a[x]<mid)r = mid-1;
		else l = mid+1;
	}
	return l;
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		memset(q,0,sizeof(q));
		int h = 0,t = 1;
		for(int j = i;j<=n;j++){
			int p = check(h,t,j);
			if(a[p]!=a[j]){
				for(int k = p+1;k<=t+1;k++){
					q[k] = q[k-1];
				}
				q[p] = j;
			}
			else t = p+1;
		}
		for(int j = h;j<=t;j++){
			cnt[q[j]]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout <<cnt[i]<<" ";
	}
	cout <<"\n";
	return 0;
}*/
