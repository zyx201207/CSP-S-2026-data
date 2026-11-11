#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int ans;
int n,m;
int l,s[N],a[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool f=1;
			for(int k=l;k>=1;k--){
				if(s[k]==a[j]){
					l=k;
					f=0;
					break;
				}
			}
			if(f)s[++l]=a[j];
		}
		for(int j=1;j<=l;j++){
			cnt[s[j]]++;
		}
		l=0;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
