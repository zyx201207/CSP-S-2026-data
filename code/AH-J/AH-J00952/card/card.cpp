#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt[200005],q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		q=1;
		long long b[200005]={0},d[200005]={0};
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=q){
				b[a[j]]=q;
				d[a[j]]=j;
			}
			else{
				q++;
				for(int k=1;k<=m;k++){
					if(d[a[k]]<=d[a[j]]) b[a[k]]=q;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]==q){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
