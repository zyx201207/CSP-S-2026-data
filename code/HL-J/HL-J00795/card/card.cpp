#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],b[500010],l=1;
map<int,int>ind,mcnt;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l=1;
		for(int j=i;j<=n;j++){
			if(ind[a[j]]==0){
				b[l]=a[j];
				ind[b[l]]=l;
				l++;
			}
			else{
				l=min(l-1,ind[a[j]])+1;
			}
		}
		for(int j=1;j<l;j++){
			mcnt[b[j]]++;
		}
		memset(b,sizeof b,0);
		ind.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<mcnt[i]<<' ';
	}
}
#undef int
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--){
		solve();
//	}
	return 0;
}
