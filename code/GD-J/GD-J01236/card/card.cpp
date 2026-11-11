#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=3e5+10;
int n,m,cnt[N],a[N];
int r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i]==a[j]) r=j;
		}
		for(int j=1;j<=r;j++){
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
