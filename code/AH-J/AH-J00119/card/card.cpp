#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt[1000005],l[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		if(cnt[a[i]]==1){
			l[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]+l[i]-1<<' ';
	}
	return 0;
}
