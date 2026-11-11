#include <bits/stdc++.h>
using namespace std;
int a[500005],l[300005],num[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
		l[a[i]]=i;
	}
	num[a[n]]=n;
	for(int i=1;i<=m;i++){
		if(i==a[n]) continue;
		int b[300005];
		for(int j=l[i]+1;j<=n;j++){
			b[a[j]]=10;
		}
		int p=l[i]-1;
		while(b[a[p]]!=10 && p>0 && a[p]!=i){
			p--;
			num[i]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<num[i]<<" ";
	return 0;
}
