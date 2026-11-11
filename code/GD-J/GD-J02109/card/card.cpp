#include <bits/stdc++.h>
using namespace std;
int n,m,k=1,sum,zd[300005],a[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	sum=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(n--){
		int ss[300005]={0},b[500005]={0},size=1;
		for(int i=k;i<=sum;i++){
			if(ss[a[i]]){
				ss[a[i]]--;
			}
			ss[a[i]]++;
			b[size]=a[i];	
			size++;
		}
		for(int i=1;i<=m;i++){
			zd[i]+=ss[i];
		}
		k++;
	}
	for(int i=1;i<m;i++){
		cout<<zd[i]<<" ";
	}
	cout<<zd[m];
	return 0;
} 
