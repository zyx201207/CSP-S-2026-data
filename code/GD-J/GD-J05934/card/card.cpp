#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],b[maxn];
map<int,int> mp,num;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		int pos=i,st=i;
		for (int j=i;j<=n;j++){
			if (mp[a[j]]) st=mp[a[j]];
			else {
				b[pos++]=a[j];
				mp[a[j]]=j;
			}
		} 
		for (int j=st;j<=n;j++) {
			mp.erase(a[j]);
			num[b[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	return 0;
} 
