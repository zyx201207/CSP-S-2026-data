#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005];
	int cnt[500005] = {0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	    cnt[a[i]]++;
	}
	int sum = 0;
	for(int i=1;i<=m;i++){
		sum += cnt[i];
		cout<<sum<<' ';
	}
	return 0;
}
